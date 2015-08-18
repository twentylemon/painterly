

#include "LineBrush.h"

LineBrush::LineBrush(int radius) : GradBrush(radius), _line_length(4*radius)
{
}

LineBrush::LineBrush(int radius, int line_length) : GradBrush(radius), _line_length(line_length)
{
}

int LineBrush::line_length() const {
    return _line_length;
}

void LineBrush::set_line_length(int line_length) {
    _line_length = line_length;
}

void LineBrush::make_stroke(cv::Mat& canvas, const cv::Point& center, const cv::Mat& reference_image, const Style& style) const {
    init_gradient(reference_image);
    cv::Scalar x, y;
    cv::polarToCart(cv::Scalar(line_length()), cv::Scalar(GRAD_DIRECTION.at<float>(center)), x, y);
    cv::Point p(-y[0], x[0]);
    cv::line(canvas, center-p/2.0, center+p/2.0, reference_image.at<cv::Vec3b>(center), radius());
}
