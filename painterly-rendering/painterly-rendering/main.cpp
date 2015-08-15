
#include "main.h"

#include <opencv2/opencv.hpp>
#include <iostream>

Global g;


int main(int argc, char** argv) {
    g.window_width = 600;
    g.window_height = 600;

    cv::Mat image = cv::imread("../images/chaika1.jpg", CV_LOAD_IMAGE_COLOR);
    cv::namedWindow("painterly rendering", CV_WINDOW_AUTOSIZE);

    cv::imshow("painterly rendering", image);

    cv::waitKey();
    return 0;
}
