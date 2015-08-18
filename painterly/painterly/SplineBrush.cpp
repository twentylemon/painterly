

#include "SplineBrush.h"

#include <vector>
#include <qdebug.h>

SplineBrush::SplineBrush(int radius) : GradBrush(radius), _min_length(4), _max_length(16), _curve(1.0)
{
}

SplineBrush::SplineBrush(int radius, double curve) : GradBrush(radius),
    _min_length(4), _max_length(16), _curve(1.0)
{
}

SplineBrush::SplineBrush(int radius, int min_length, int max_length) : GradBrush(radius),
    _min_length(min_length), _max_length(max_length), _curve(1.0)
{
}

SplineBrush::SplineBrush(int radius, int min_length, int max_length, double curve) : GradBrush(radius),
    _min_length(min_length), _max_length(max_length), _curve(curve)
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

double SplineBrush::curve() const {
    return _curve;
}

void SplineBrush::set_curve(double curve) {
    _curve = curve;
}


void SplineBrush::make_stroke(cv::Mat& canvas, const cv::Point& center, const cv::Mat& reference_image, const Style& style) const {
    init_gradient(reference_image);
    std::vector<std::vector<cv::Point>> contour;
    contour.emplace_back();
    std::vector<cv::Point>& points = contour.back();
    points.emplace_back(center);

    cv::Vec3b center_color = reference_image.at<cv::Vec3b>(center);
    cv::Point point = center;
    cv::Point2d previous(0.0, 0.0);
    cv::Rect bounds(0, 0, canvas.cols, canvas.rows);
    while (points.size() < max_length() && point.inside(bounds)) {
        if (points.size() > min_length() && cv::norm(reference_image.at<cv::Vec3b>(point), canvas.at<cv::Vec3b>(point)) < cv::norm(reference_image.at<cv::Vec3b>(point), center_color)) {
            break;
        }
        if (std::fabs(GRAD.at<float>(point)) <= 0.001) {
            break;
        }
        cv::Scalar gx, gy;
        cv::polarToCart(cv::Scalar(1.0), cv::Scalar(GRAD_DIRECTION.at<float>(point)), gx, gy);
        cv::Point2d d(-gy[0], gx[0]);
        if (previous.ddot(d) < 0.0) {
            d = -d;
        }
        d = curve()*d - (1.0-curve())*previous;
        d = d / std::sqrt(d.ddot(d));
        point += cv::Point(radius()*d.x, radius()*d.y);
        previous = d;
        points.emplace_back(point);
    }
    cv::polylines(canvas, points, false, center_color, radius());
}
