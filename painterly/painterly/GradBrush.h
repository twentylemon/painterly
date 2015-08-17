
#ifndef GRADBRUSH_H
#define GRADBRUSH_H

#include "Brush.h"

class GradBrush : public Brush
{
public:
    GradBrush(int radius);

    virtual void reset() override;

protected:
    static void init_gradient(const cv::Mat& reference_image);
    static cv::Mat GRAD;
    static cv::Mat GRAD_DIRECTION;
};
#endif
