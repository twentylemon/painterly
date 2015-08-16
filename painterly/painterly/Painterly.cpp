

#include "Painterly.h"

#include <algorithm>

const std::string Painterly::SOURCE_NAME = "Source Image";
const std::string Painterly::PAINTED_NAME = "Painted Image";

Painterly::Painterly()
{
}

Painterly::Painterly(const std::string& image_file)
{
    set_image_file(image_file);
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

void Painterly::set_image_file(const std::string& image_file) {
    _source = cv::imread(image_file, CV_LOAD_IMAGE_COLOR);
}

void Painterly::init_paint() {
    _canvas = cv::Mat();
    cv::namedWindow(SOURCE_NAME, cv::WINDOW_AUTOSIZE);
    cv::namedWindow(PAINTED_NAME, cv::WINDOW_AUTOSIZE);
    cv::imshow(SOURCE_NAME, source());
}


void Painterly::paint(const std::string& image_file) {
    set_image_file(image_file);
    paint();
}

void Painterly::paint() {
    init_paint();
    std::for_each(brushes().begin(), brushes().end(), [this](const std::unique_ptr<Brush>& brush){
        cv::Mat reference_image;
        cv::GaussianBlur(source(), reference_image, cv::Size(31, 31), 0, 0, cv::BorderTypes::BORDER_DEFAULT);
        paint_layer(reference_image, brush);
    });
}

void Painterly::paint_layer(const cv::Mat& reference_image, const std::unique_ptr<Brush>& brush) {
}
