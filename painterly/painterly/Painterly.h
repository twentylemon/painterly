
#ifndef PAINTERLY_H
#define PAINTERLY_H

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

    void set_image_file(const std::string& image_file);

    void add_brush(Brush* brush);
    
    void remove_brush(int index);
    void clear_brushes();

    void paint(const std::string& image_file);
    void paint();

private:
    void init_paint();

    void paint_layer(const cv::Mat& reference_image, const std::unique_ptr<Brush>& brush);

    std::vector<std::unique_ptr<Brush>> _brushes;
    cv::Mat _canvas;
    cv::Mat _source;
};
#endif
