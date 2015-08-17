

#include "GradBrush.h"


cv::Mat GradBrush::GRAD;
cv::Mat GradBrush::GRAD_DIRECTION;

GradBrush::GradBrush(int radius) : Brush(radius)
{
}

void GradBrush::reset() {
    GRAD.release();
    GRAD_DIRECTION.release();
}

void GradBrush::init_gradient(const cv::Mat& reference_image) {
    if (GRAD.empty()) {
        cv::Mat grad_x, grad_y;
        cv::Sobel(reference_image, grad_x, CV_32F, 1, 0);
        cv::Sobel(reference_image, grad_y, CV_32F, 0, 1);
        cv::addWeighted(grad_x, 0.5, grad_y, 0.5, 0.0, GRAD);
        GRAD_DIRECTION = cv::Mat(GRAD.rows, GRAD.cols, CV_32F);
        cv::phase(grad_x, grad_y, GRAD_DIRECTION);
    }
}
