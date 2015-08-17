
#ifndef LINEBRUSH_H
#define LINEBRUSH_H

#include "GradBrush.h"

class LineBrush : public GradBrush
{
public:
    LineBrush(int radius);
    LineBrush(int radius, int line_length);

    int line_length() const;
    void set_line_length(int line_length);

    virtual void make_stroke(cv::Mat& canvas, const cv::Point& center, const cv::Mat& reference_image) const override;

private:
    int _line_length;
};
#endif
