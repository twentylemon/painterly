
#ifndef SPLINEBRUSH_H
#define SPLINEBRUSH_H

#include "GradBrush.h"

class SplineBrush : public GradBrush
{
public:
    SplineBrush(int radius);
    SplineBrush(int radius, double curve);
    SplineBrush(int radius, int min_length, int max_length);
    SplineBrush(int radius, int min_length, int max_length, double curve);

    int min_length() const;
    void set_min_length(int min_length);
    int max_length() const;
    void set_max_length(int max_length);
    double curve() const;
    void set_curve(double curve);

    virtual void make_stroke(cv::Mat& canvas, const cv::Point& center, const cv::Mat& reference_image) const override;

private:
    int _min_length;
    int _max_length;
    double _curve;
};
#endif
