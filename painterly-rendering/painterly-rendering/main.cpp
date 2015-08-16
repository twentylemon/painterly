
#include "main.h"

#include <opencv2/opencv.hpp>
#include <iostream>

Global g;


int main(int argc, char** argv) {
    g.window_width = 600;
    g.window_height = 600;

    cv::Mat image = cv::imread("../images/chaika1.jpg", CV_LOAD_IMAGE_COLOR);
    cv::namedWindow("painterly rendering", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
    cv::imshow("original", image);

    cv::GaussianBlur(image, image, cv::Size(3, 3), 0, 0, cv::BorderTypes::BORDER_DEFAULT);
    //cv::cvtColor(image, image, CV_RGB2GRAY);

    cv::Mat grad, grad_x, grad_y;
    cv::Sobel(image, grad_x, CV_16S, 1, 0, 3, 1, 0, cv::BorderTypes::BORDER_DEFAULT);
    cv::convertScaleAbs(grad_x, grad_x);
    cv::Sobel(image, grad_y, CV_16S, 1, 0, 3, 1, 0, cv::BorderTypes::BORDER_DEFAULT);
    cv::convertScaleAbs(grad_y, grad_y);

    cv::addWeighted(grad_x, 0.5, grad_y, 0.5, 0, grad);

    cv::imshow("painterly rendering", image);

    cv::waitKey();
    return 0;
}
