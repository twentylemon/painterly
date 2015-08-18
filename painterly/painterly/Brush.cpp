

#include "Brush.h"

cv::RNG rng;

int clamp(int val) {
    if (val < 0) { return 0; }
    if (val > 255) { return 255; }
    return val;
}

Brush::Brush() : _radius(0)
{
}

Brush::Brush(int radius) : _radius(radius)
{
}

int Brush::radius() const {
    return _radius;
}

void Brush::set_radius(int radius) {
    _radius = radius;
}

void Brush::reset() {
}

bool Brush::operator<(const Brush& rhs) const {
    return radius() < rhs.radius();
}

const cv::Vec3b Brush::get_color(const cv::Point center, const cv::Mat& reference_image, const Style& style) const {
    cv::Vec3b color = reference_image.at<cv::Vec3b>(center);
    color[0] = clamp(color[0] + color[0] * (rng.uniform(-0.5, 0.5) * style.blue_jitter()));
    color[1] = clamp(color[1] + color[1] * (rng.uniform(-0.5, 0.5) * style.green_jitter()));
    color[2] = clamp(color[2] + color[2] * (rng.uniform(-0.5, 0.5) * style.red_jitter()));
    cv::cvtColor(color, color, CV_RGB2HSV);
    color[0] = clamp(color[0] + color[0] * (rng.uniform(-0.5, 0.5) * style.hue_jitter()));
    color[1] = clamp(color[1] + color[1] * (rng.uniform(-0.5, 0.5) * style.saturation_jitter()));
    color[2] = clamp(color[2] + color[2] * (rng.uniform(-0.5, 0.5) * style.value_jitter()));
    cv::cvtColor(color, color, CV_HSV2RGB);
    return color;
}
