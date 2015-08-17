

#include "SplineBrush.h"

#include <vector>

SplineBrush::SplineBrush(int radius) : GradBrush(radius), _min_length(4), _max_length(16)
{
}

SplineBrush::SplineBrush(int radius, int min_length, int max_length) : GradBrush(radius),
    _min_length(min_length), _max_length(max_length)
{
}

int SplineBrush::min_length() const {
    return _min_length;
}

void SplineBrush::set_min_length(int min_length) {
    _min_length = min_length;
}

int SplineBrush::max_length() const {
    return _max_length;
}

void SplineBrush::set_max_length(int max_length) {
    _max_length = max_length;
}


void SplineBrush::make_stroke(cv::Mat& canvas, const cv::Point& center, const cv::Mat& reference_image) const {
    init_gradient(reference_image);
    std::vector<cv::Point> points;
    points.emplace_back(center);

    cv::Vec3b center_color = reference_image.at<cv::Vec3b>(center);
    cv::Point point = center;
    cv::Point previous(0, 0);
    for (int i = 0; i < max_length(); i++) {
        if (i > min_length() && cv::norm(reference_image.at<cv::Vec3b>(point), canvas.at<cv::Vec3b>(point)) < cv::norm(reference_image.at<cv::Vec3b>(point), center_color)) {
            break;
        }
        
    }
}
