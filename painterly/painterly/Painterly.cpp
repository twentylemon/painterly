

#include "Painterly.h"

#include <cmath>
#include <algorithm>
#include <numeric>
#include <ppl.h>

#include <qdebug.h>

#include "Stroke.h"

#ifndef _DEBUG
#define USE_PPL
#endif

#ifdef USE_PPL
#include <concurrent_vector.h>
#endif


int handle_error(int status, const char* func_name, const char* err_msg, const char* file_name, int line, void* userdata) {
    qDebug() << err_msg;
    return 0;
}

const std::string Painterly::SOURCE_NAME = "Source Image";
const std::string Painterly::PAINTED_NAME = "Painted Image";

Painterly::Painterly() : _style()
{
}

Painterly::Painterly(const std::string& image_file) : _style()
{
    set_image_file(image_file);
}


Style& Painterly::style() {
    return _style;
}

void Painterly::set_style(const Style& style) {
    _style = style;
}

std::vector<std::unique_ptr<Brush>>& Painterly::brushes() {
    return _brushes;
}

const std::vector<std::unique_ptr<Brush>>& Painterly::brushes() const {
    return _brushes;
}

const cv::Mat& Painterly::source() const {
    return _source;
}

cv::Mat& Painterly::frame() {
    return _frame;
}
cv::Mat& Painterly::prev_source() {
    return _prev_source;
}

cv::Rect& Painterly::bounds() {
    return _bounds;
}

void Painterly::add_brush(Brush* brush) {
    brushes().emplace_back(brush);
    std::sort(brushes().begin(), brushes().end(), [](std::unique_ptr<Brush>& lhs, std::unique_ptr<Brush>& rhs){
        return lhs->operator<(*rhs);
    });
}
    
void Painterly::remove_brush(int index) {
    brushes().erase(brushes().begin() + index);
}

void Painterly::clear_brushes() {
    brushes().clear();
}


void Painterly::save_canvas(const std::string& filename) const {
    cv::imwrite(filename, _frame);
}

void Painterly::set_image_file(const std::string& image_file) {
    _source = cv::imread(image_file, CV_LOAD_IMAGE_COLOR);
    _source.convertTo(_source, CV_8UC3);
}

void Painterly::reset_brushes() {
    std::for_each(brushes().begin(), brushes().end(), [](const std::unique_ptr<Brush>& brush){ brush->reset(); });
}

void Painterly::init_paint() {
    _frame = cv::Mat(source().rows, source().cols, CV_8UC3, cv::Vec3b(0, 0, 0));
    _prev_source.release();
    _video_error.clear();
    _bounds = cv::Rect(0, 0, frame().cols, frame().rows);
    cv::namedWindow(SOURCE_NAME, cv::WINDOW_AUTOSIZE);
    cv::namedWindow(PAINTED_NAME, cv::WINDOW_AUTOSIZE);
    reset_brushes();
}


cv::Mat Painterly::difference(const cv::Mat& reference_image) {
    cv::Mat diff(frame().rows, frame().cols, CV_32FC1);
#ifdef USE_PPL
    concurrency::parallel_for(0, diff.rows, [&](int row){
        concurrency::parallel_for(0, diff.cols, [&,row](int col){
#else
    for (int row = 0; row < diff.rows; row++) {
        for (int col = 0; col < diff.cols; col++) {
#endif
            if (frame().at<cv::Vec3b>(row, col) == cv::Vec3b(0, 0, 0)) {
                diff.at<float>(row, col) = 1000000.0f;
            }
            else {
                diff.at<float>(row, col) = cv::norm(frame().at<cv::Vec3b>(row, col), reference_image.at<cv::Vec3b>(row, col));
            }
#ifdef USE_PPL
        });
    });
#else
        }
    }
#endif
    return diff;
}

bool Painterly::frame_difference(const cv::Range& xrange, const cv::Range& yrange, double threshold) {
    if (prev_source().empty()) {
        return true;
    }
    //return cv::norm(source()(xrange, yrange), frame()(xrange, yrange)) / (xrange.size()*yrange.size()) > threshold;
    double diff = cv::norm(source()(xrange, yrange), frame()(xrange, yrange)) / (xrange.size()*yrange.size());
    std::tuple<int,int,int,int> key = std::make_tuple(xrange.start, xrange.end, yrange.start, yrange.end);
    auto it = _video_error.lower_bound(key);
    if (it != _video_error.end() && !(_video_error.key_comp()(key, it->first))) {
        //if (diff > threshold/4.0)
            it->second += diff;
    }
    else {
        it = _video_error.emplace_hint(it, key, diff);
    }
    if (it->second > threshold) {
        it->second = 0.0;
        return true;
    }
    return false;
}

void Painterly::video_off_frame() {
    reset_brushes();
    std::for_each(brushes().rbegin(), brushes().rend(), [this](const std::unique_ptr<Brush>& brush){
        cv::Mat reference_image;
        int size = static_cast<int>(style().blur_factor() * brush->radius());
        if (size % 2 == 0) {
            size++;
        }
        cv::GaussianBlur(source(), reference_image, cv::Size(size, size), size, size);
        cv::Mat diff = difference(reference_image);
        int grid = static_cast<int>(style().grid_size() * brush->radius());
        concurrency::parallel_for(0, diff.rows, grid, [this,&diff,&brush,grid](int row){
            concurrency::parallel_for(0, diff.cols, grid, [this,&diff,&brush,grid,row](int col){
                cv::Range xrange = cv::Range(std::max(row-grid/2, 0), std::min(row+grid/2, diff.rows));
                cv::Range yrange = cv::Range(std::max(col-grid/2, 0), std::min(col+grid/2, diff.cols));
                frame_difference(xrange, yrange, 1000000.0);
            });
        });
    });
    prev_source() = source().clone();
}


double Painterly::paint(const std::string& image_file) {
    set_image_file(image_file);
    init_paint();
    return paint(false);
}

double Painterly::paint(cv::VideoCapture& video, const std::string& out_file) {
    cv::VideoWriter out(out_file, CV_FOURCC('M','J','P','G'), static_cast<int>(std::ceil(video.get(CV_CAP_PROP_FPS))) / 3,
        cv::Size(video.get(CV_CAP_PROP_FRAME_WIDTH), video.get(CV_CAP_PROP_FRAME_HEIGHT)));
    video >> _source;
    init_paint();
    double total_time = paint(true, true);
    out << frame();
    
    while (video.read(_source) && video.read(_source) && video.read(_source)) {
        reset_brushes();
        total_time += paint(true);
        out << frame();
        prev_source() = source().clone();
        cv::waitKey(1); // wait for the paint event
    }
    
    /*
    int frame_num = 0;
    while (video.read(_source) && video.read(_source) && video.read(_source)) {
        frame_num++;
        if (frame_num % 3 == 0) {
            reset_brushes();
            total_time += paint(true);
            out << frame();
            prev_source() = source().clone();
            cv::waitKey(1); // wait for the paint event
        }
        else {
            video_off_frame();
        }
    }
    */
    return total_time;
}

double Painterly::paint(bool video, bool first_frame) {
    video = !video; // for randomization
    double time = static_cast<double>(cv::getTickCount());
    std::for_each(brushes().rbegin(), brushes().rend(), [this,&first_frame,video](const std::unique_ptr<Brush>& brush){
        cv::Mat reference_image;
        int size = static_cast<int>(style().blur_factor() * brush->radius());
        if (size % 2 == 0) {
            size++;
        }
        cv::GaussianBlur(source(), reference_image, cv::Size(size, size), size, size);
        paint_layer(reference_image, brush, first_frame, video);
        first_frame = false;
        if (video) {
            cv::imwrite("D:/pics/results/" + std::to_string(brush->radius()) + ".jpg", frame());
        }
        //cv::namedWindow(std::to_string(brush->radius()), cv::WINDOW_AUTOSIZE);
        //cv::imshow(std::to_string(brush->radius()), canvas());
    });
    if (video) { // actually if not a video
        cv::Mat mask;
        cv::inRange(frame(), cv::Scalar(0,0,0), cv::Scalar(0,0,0), mask);
        source().copyTo(frame(), mask);
    }
    time = (static_cast<double>(cv::getTickCount()) - time) / cv::getTickFrequency();
    cv::imshow(SOURCE_NAME, source());
    cv::imshow(PAINTED_NAME, frame());
    return time;
}

void Painterly::paint_layer(const cv::Mat& reference_image, const std::unique_ptr<Brush>& brush, bool refresh, bool random) {
    //cv::redirectError(handle_error);
    cv::Mat diff = refresh ? cv::Mat::zeros(reference_image.rows, reference_image.cols, CV_32F) : difference(reference_image);
    int grid = static_cast<int>(style().grid_size() * brush->radius());
#ifdef USE_PPL
    concurrency::concurrent_vector<Stroke> strokes;
    strokes.reserve(2 * diff.rows/grid * diff.cols/grid);
    concurrency::parallel_for(0, diff.rows, grid, [this,&diff,&strokes,&brush,grid,refresh](int row){
        concurrency::parallel_for(0, diff.cols, grid, [this,&diff,&strokes,&brush,grid,refresh,row](int col){
#else
    std::vector<Stroke> strokes;
    strokes.reserve(2 * diff.rows/grid * diff.cols/grid);
    for (int row = 0; row < diff.rows; row += grid) {
        for (int col = 0; col < diff.cols; col += grid) {
#endif
            cv::Range xrange = cv::Range(std::max(row-grid/2, 0), std::min(row+grid/2, diff.rows));
            cv::Range yrange = cv::Range(std::max(col-grid/2, 0), std::min(col+grid/2, diff.cols));
            cv::Mat area = diff(xrange, yrange);
            if (refresh || (frame_difference(xrange, yrange, style().video_threshold()) && cv::sum(area)[0] > style().threshold())) {
                cv::Point max_loc;
                cv::minMaxLoc(area, nullptr, nullptr, nullptr, &max_loc);
                max_loc += cv::Point(col, row);
                if (max_loc.inside(bounds())) {
                    strokes.push_back(Stroke(brush.get(), max_loc));
                }
            }
#ifdef USE_PPL
        });
    });
#else
        }
    }
#endif
    if (random) {
        std::random_shuffle(strokes.begin(), strokes.end());
    }
    //qDebug() << brush->radius() << "\t" << strokes.size();
    std::for_each(strokes.begin(), strokes.end(), [this,&reference_image](const Stroke& stroke) {
        stroke(frame(), reference_image, style());
    });
}
