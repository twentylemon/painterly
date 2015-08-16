
#ifndef BRUSH_H
#define BRUSH_H

#include <opencv2/opencv.hpp>

class Brush
{
public:
    Brush();

    Brush(int radius);

    int radius() const;

    void set_radius(int radius);

    virtual void make_stroke(cv::Mat& canvas, const cv::Point& center, const cv::Mat& reference_image) const = 0;

    bool operator<(const Brush& rhs) const;

private:
    int _radius;
};
#endif
