

#include "Painterly.h"

#include <algorithm>
#include <numeric>

#include <qdebug.h>

#include "Stroke.h"

#ifndef _DEBUG
#define USE_PPL
#endif

#ifdef USE_PPL
#include <ppl.h>
#include <concurrent_vector.h>
#endif



int handle_error(int status, const char* func_name, const char* err_msg, const char* file_name, int line, void* userdata) {
    qDebug() << err_msg;
    return 0;
}

const std::string Painterly::SOURCE_NAME = "Source Image";
const std::string Painterly::PAINTED_NAME = "Painted Image";

const float DEFAULT_THRESHOLD = 100.0f;

Painterly::Painterly() :
    _approx_threshold(DEFAULT_THRESHOLD),
    _blur_factor(1.0),
    _grid_size(1.0)
{
    _rgb_jitter.fill(0.0);
    _hsv_jitter.fill(0.0);
}

Painterly::Painterly(const std::string& image_file) :
    _approx_threshold(DEFAULT_THRESHOLD),
    _blur_factor(1.0),
    _grid_size(1.0)
{
    _rgb_jitter.fill(0.0);
    _hsv_jitter.fill(0.0);
    set_image_file(image_file);
}


double Painterly::threshold() const {
    return _approx_threshold;
}

void Painterly::set_threshold(double threshold) {
    _approx_threshold = threshold;
}

double Painterly::blur_factor() const {
    return _blur_factor;
}

void Painterly::set_blur_factor(double blur_factor) {
    _blur_factor = blur_factor;
}

double Painterly::grid_size() const {
    return _grid_size;
}

void Painterly::set_grid_size(double grid_size) {
    _grid_size = grid_size;
}

std::array<double,3>& Painterly::rgb_jitter() {
    return _rgb_jitter;
}

const std::array<double,3>& Painterly::rgb_jitter() const {
    return _rgb_jitter;
}

void Painterly::set_rgb_jitter(double red, double green, double blue) {
    set_red_jitter(red);
    set_green_jitter(green);
    set_blue_jitter(blue);
}

double Painterly::red_jitter() const {
    return _rgb_jitter[0];
}

void Painterly::set_red_jitter(double red) {
    _rgb_jitter[0] = red;
}

double Painterly::green_jitter() const {
    return _rgb_jitter[1];
}

void Painterly::set_green_jitter(double green) {
    _rgb_jitter[1] = green;
}

double Painterly::blue_jitter() const {
    return _rgb_jitter[2];
}

void Painterly::set_blue_jitter(double blue) {
    _rgb_jitter[2] = blue;
}

std::array<double,3>& Painterly::hsv_jitter() {
    return _hsv_jitter;
}

const std::array<double,3>& Painterly::hsv_jitter() const {
    return _hsv_jitter;
}

double Painterly::hue_jitter() const {
    return _hsv_jitter[0];
}

void Painterly::set_hue_jitter(double hue) {
    _hsv_jitter[0] = hue;
}

double Painterly::saturation_jitter() const {
    return _hsv_jitter[1];
}

void Painterly::set_saturation_jitter(double saturation) {
    _hsv_jitter[1] = saturation;
}

double Painterly::value_jitter() const {
    return _hsv_jitter[2];
}

void Painterly::set_value_jitter(double value) {
    _hsv_jitter[2] = value;
}

void Painterly::set_hsv_jitter(double hue, double saturation, double value) {
    set_hue_jitter(hue);
    set_saturation_jitter(saturation);
    set_value_jitter(value);
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

cv::Mat& Painterly::canvas() {
    return _canvas;
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
    cv::imwrite(filename, _canvas);
}

void Painterly::set_image_file(const std::string& image_file) {
    _source = cv::imread(image_file, CV_LOAD_IMAGE_COLOR);
    _source.convertTo(_source, CV_8UC3);
    _canvas = cv::Mat(source().rows, source().cols, CV_8UC3);
}

void Painterly::init_paint() {
    _canvas = cv::Scalar(0, 0, 0);
    _bounds = cv::Rect(0, 0, canvas().cols, canvas().rows);
    cv::namedWindow(SOURCE_NAME, cv::WINDOW_AUTOSIZE);
    cv::namedWindow(PAINTED_NAME, cv::WINDOW_AUTOSIZE);
    cv::imshow(SOURCE_NAME, source());
    std::for_each(brushes().begin(), brushes().end(), [](const std::unique_ptr<Brush>& brush){ brush->reset(); });
}


cv::Mat Painterly::difference(const cv::Mat& reference_image) {
    cv::Mat diff(canvas().rows, canvas().cols, CV_32FC1);
#ifdef USE_PPL
    concurrency::parallel_for(0, diff.rows, [&](int row){
        concurrency::parallel_for(0, diff.cols, [&,row](int col){
#else
    for (int row = 0; row < diff.rows; row++) {
        for (int col = 0; col < diff.cols; col++) {
#endif
            if (canvas().at<cv::Vec3b>(row, col) == cv::Vec3b(0, 0, 0)) {
                diff.at<float>(row, col) = 1000000.0f;
            }
            else {
                diff.at<float>(row, col) = cv::norm(canvas().at<cv::Vec3b>(row, col), reference_image.at<cv::Vec3b>(row, col));
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


double Painterly::paint(const std::string& image_file) {
    set_image_file(image_file);
    return paint();
}

double Painterly::paint() {
    double start = static_cast<double>(cv::getTickCount());
    init_paint();
    std::for_each(brushes().rbegin(), brushes().rend(), [this](const std::unique_ptr<Brush>& brush){
        cv::Mat reference_image;
        int size = static_cast<int>(blur_factor() * brush->radius());
        if (size % 2 == 0) {
            size++;
        }
        cv::GaussianBlur(source(), reference_image, cv::Size(size, size), size, size);
        paint_layer(reference_image, brush);
        //cv::namedWindow(std::to_string(brush->radius()), cv::WINDOW_AUTOSIZE);
        //cv::imshow(std::to_string(brush->radius()), canvas());
    });
    /*
    cv::Mat mask;
    cv::inRange(canvas(), cv::Scalar(0,0,0), cv::Scalar(0,0,0), mask);
    source().copyTo(canvas(), mask);
    */
    cv::imshow(PAINTED_NAME, canvas());
    return (static_cast<double>(cv::getTickCount()) - start) / cv::getTickFrequency();
}

void Painterly::paint_layer(const cv::Mat& reference_image, const std::unique_ptr<Brush>& brush) {
    cv::redirectError(handle_error);
    cv::Mat diff = difference(reference_image);
    int grid = static_cast<int>(grid_size() * brush->radius());
#ifdef USE_PPL
    concurrency::concurrent_vector<Stroke> strokes;
    strokes.reserve(2 * reference_image.rows/grid * reference_image.cols/grid);
    concurrency::parallel_for(0, reference_image.rows, grid, [this,&reference_image,&diff,&strokes,&brush,grid](int row){
        concurrency::parallel_for(0, reference_image.cols, grid, [this,&reference_image,&diff,&strokes,&brush,grid,row](int col){
#else
    std::vector<Stroke> strokes;
    strokes.reserve(2 * reference_image.rows/grid * reference_image.cols/grid);
    for (int row = 0; row < reference_image.rows; row += grid) {
        for (int col = 0; col < reference_image.cols; col += grid) {
#endif
            cv::Range xrange = cv::Range(std::max(row-grid/2, 0), std::min(row+grid/2, reference_image.rows));
            cv::Range yrange = cv::Range(std::max(col-grid/2, 0), std::min(col+grid/2, reference_image.cols));
            cv::Mat area = diff(xrange, yrange);
            //qDebug() << cv::sum(area)[0] / (grid * grid);
            if (cv::sum(area)[0] / (grid * grid) > threshold()) {
                cv::Point max_loc;
                cv::minMaxLoc(area, nullptr, nullptr, nullptr, &max_loc);
                strokes.push_back(Stroke(brush.get(), cv::Point(std::min(reference_image.cols-1, max_loc.x+col), std::min(reference_image.rows-1, max_loc.y+row))));
            }
#ifdef USE_PPL
        });
    });
#else
        }
    }
#endif
    std::random_shuffle(strokes.begin(), strokes.end());
    qDebug() << strokes.size();
    std::for_each(strokes.begin(), strokes.end(), [this,&reference_image](const Stroke& stroke) {
        if (stroke.point().inside(bounds())) {
            stroke(canvas(), reference_image);
        }
    });
}
