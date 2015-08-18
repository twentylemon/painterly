
#ifndef BRUSH_H
#define BRUSH_H

#include <opencv2/opencv.hpp>

#include "Style.h"

class Brush
{
public:
    Brush();

    Brush(int radius);

    int radius() const;
    void set_radius(int radius);

    virtual void reset();

    virtual void make_stroke(cv::Mat& canvas, const cv::Point& center, const cv::Mat& reference_image, const Style& style) const = 0;

    bool operator<(const Brush& rhs) const;

    const cv::Vec3b get_color(const cv::Point center, const cv::Mat& reference_image, const Style& style) const;

private:
    int _radius;
};
#endif
