

#include "Stroke.h"


Stroke::Stroke(Brush* brush, const cv::Point& point) :
    _brush(brush),
    _point(point)
{
}


const Brush* Stroke::brush() const {
    return _brush;
}

const cv::Point& Stroke::point() const {
    return _point;
}


void Stroke::operator()(cv::Mat& canvas, const cv::Mat& reference_image) const {
    brush()->make_stroke(canvas, point(), reference_image);
}
