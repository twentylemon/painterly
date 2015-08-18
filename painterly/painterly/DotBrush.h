
#ifndef DOTBRUSH_H
#define DOTBRUSH_H

#include "Brush.h"

class DotBrush :
    public Brush
{
public:
    DotBrush(int radius);

    virtual void make_stroke(cv::Mat& canvas, const cv::Point& center, const cv::Mat& reference_image, const Style& style) const override;
};
#endif
