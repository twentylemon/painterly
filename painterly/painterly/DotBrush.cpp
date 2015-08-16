

#include "DotBrush.h"


DotBrush::DotBrush(int radius) : Brush(radius)
{
}


void DotBrush::make_stroke(cv::Mat& canvas, const cv::Point& center, const cv::Mat& reference_image) const {
    cv::circle(canvas, center, radius(), reference_image.at<cv::Vec3b>(center), CV_FILLED);
}
