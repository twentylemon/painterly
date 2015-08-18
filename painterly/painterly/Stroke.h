
#ifndef STROKE_H
#define STROKE_H

#include <opencv2/opencv.hpp>

#include "Brush.h"

class Stroke
{
public:
    Stroke(Brush* brush, const cv::Point& point);

    const Brush* brush() const;
    const cv::Point& point() const;

    void operator()(cv::Mat& canvas, const cv::Mat& reference_image, const Style& style) const;

private:
    Brush* _brush;
    cv::Point _point;
};
#endif
