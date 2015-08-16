
#ifndef PAINTERLY_H
#define PAINTERLY_H

#include <array>
#include <string>
#include <vector>
#include <memory>

#include <opencv2/opencv.hpp>

#include "Brush.h"

class Painterly
{
public:
    const static std::string SOURCE_NAME;
    const static std::string PAINTED_NAME;

    Painterly();
    Painterly(const std::string& image_file);

    std::vector<std::unique_ptr<Brush>>& brushes();
    const std::vector<std::unique_ptr<Brush>>& brushes() const;

    const cv::Mat& source() const;

    double threshold() const;
    void set_threshold(double threshold);
    double blur_factor() const;
    void set_blur_factor(double blur_factor);
    double grid_size() const;
    void set_grid_size(double grid_size);
    std::array<double,3>& rgb_jitter();
    const std::array<double,3>& rgb_jitter() const;
    void set_rgb_jitter(double red, double green, double blue);
    double red_jitter() const;
    void set_red_jitter(double red);
    double green_jitter() const;
    void set_green_jitter(double green);
    double blue_jitter() const;
    void set_blue_jitter(double blue);
    std::array<double,3>& hsv_jitter();
    const std::array<double,3>& hsv_jitter() const;
    void set_hsv_jitter(double hue, double saturation, double value);
    double hue_jitter() const;
    void set_hue_jitter(double hue);
    double saturation_jitter() const;
    void set_saturation_jitter(double saturation);
    double value_jitter() const;
    void set_value_jitter(double value);


    void set_image_file(const std::string& image_file);

    void add_brush(Brush* brush);
    void remove_brush(int index);
    void clear_brushes();

    void paint(const std::string& image_file);
    void paint();

private:
    void init_paint();

    void paint_layer(const cv::Mat& reference_image, const std::unique_ptr<Brush>& brush);

    cv::Mat difference(const cv::Mat& reference_image);

    cv::Mat& canvas();

    std::vector<std::unique_ptr<Brush>> _brushes;
    cv::Mat _canvas;
    cv::Mat _source;

    double _approx_threshold;
    double _blur_factor;
    double _grid_size;
    std::array<double,3> _rgb_jitter;
    std::array<double,3> _hsv_jitter;
};
#endif
