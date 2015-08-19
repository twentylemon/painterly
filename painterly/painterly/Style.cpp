

#include "Style.h"


Style::Style()
{
    impressionist();
}

void Style::impressionist() {
    set_threshold(100.0);
    set_video_threshold(10.0);
    set_blur_factor(0.5);
    set_alpha(1.0);
    set_grid_size(1.0);
    set_rgb_jitter(0.0, 0.0, 0.0);
    set_hsv_jitter(0.0, 0.0, 0.0);
}

void Style::expressionist() {
    set_threshold(50.0);
    set_video_threshold(100.0);
    set_blur_factor(0.5);
    set_alpha(0.7);
    set_grid_size(1.0);
    set_rgb_jitter(0.0, 0.0, 0.0);
    set_hsv_jitter(0.0, 0.0, 0.5);
}

void Style::colorish_wash() {
    set_threshold(200.0);
    set_video_threshold(100.0);
    set_blur_factor(0.5);
    set_alpha(0.5);
    set_grid_size(1.0);
    set_rgb_jitter(0.3, 0.3, 0.3);
    set_hsv_jitter(0.0, 0.0, 0.0);
}

void Style::pointillist() {
    set_threshold(100.0);
    set_video_threshold(100.0);
    set_blur_factor(0.5);
    set_alpha(1.0);
    set_grid_size(0.5);
    set_rgb_jitter(0.0, 0.0, 0.0);
    set_hsv_jitter(0.3, 0.0, 1.0);
}

double Style::video_threshold() const {
    return _video_threshold;
}

void Style::set_video_threshold(double video_threshold) {
    _video_threshold = video_threshold;
}

double Style::threshold() const {
    return _approx_threshold;
}

void Style::set_threshold(double threshold) {
    _approx_threshold = threshold;
}

double Style::blur_factor() const {
    return _blur_factor;
}

void Style::set_blur_factor(double blur_factor) {
    _blur_factor = blur_factor;
}

double Style::grid_size() const {
    return _grid_size;
}

void Style::set_grid_size(double grid_size) {
    _grid_size = grid_size;
}

double Style::alpha() const {
    return _alpha;
}

void Style::set_alpha(double alpha) {
    _alpha = alpha;
}

std::array<double,3>& Style::rgb_jitter() {
    return _rgb_jitter;
}

const std::array<double,3>& Style::rgb_jitter() const {
    return _rgb_jitter;
}

void Style::set_rgb_jitter(double red, double green, double blue) {
    set_red_jitter(red);
    set_green_jitter(green);
    set_blue_jitter(blue);
}

double Style::red_jitter() const {
    return _rgb_jitter[0];
}

void Style::set_red_jitter(double red) {
    _rgb_jitter[0] = red;
}

double Style::green_jitter() const {
    return _rgb_jitter[1];
}

void Style::set_green_jitter(double green) {
    _rgb_jitter[1] = green;
}

double Style::blue_jitter() const {
    return _rgb_jitter[2];
}

void Style::set_blue_jitter(double blue) {
    _rgb_jitter[2] = blue;
}

std::array<double,3>& Style::hsv_jitter() {
    return _hsv_jitter;
}

const std::array<double,3>& Style::hsv_jitter() const {
    return _hsv_jitter;
}

double Style::hue_jitter() const {
    return _hsv_jitter[0];
}

void Style::set_hue_jitter(double hue) {
    _hsv_jitter[0] = hue;
}

double Style::saturation_jitter() const {
    return _hsv_jitter[1];
}

void Style::set_saturation_jitter(double saturation) {
    _hsv_jitter[1] = saturation;
}

double Style::value_jitter() const {
    return _hsv_jitter[2];
}

void Style::set_value_jitter(double value) {
    _hsv_jitter[2] = value;
}

void Style::set_hsv_jitter(double hue, double saturation, double value) {
    set_hue_jitter(hue);
    set_saturation_jitter(saturation);
    set_value_jitter(value);
}
