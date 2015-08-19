
#ifndef PAINTERLY_H
#define PAINTERLY_H

#include <string>
#include <vector>
#include <memory>

#include <opencv2/opencv.hpp>

#include "Brush.h"
#include "Style.h"

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

    Style& style();
    void set_style(const Style& style);

    void add_brush(Brush* brush);
    void remove_brush(int index);
    void clear_brushes();

    void save_canvas(const std::string& filename) const;

    double paint(const std::string& image_file);
    double paint(cv::VideoCapture& video, const std::string& out_file);

private:
    void set_image_file(const std::string& image_file);
    void reset_brushes();
    void init_paint();
    bool read_frame(cv::VideoCapture& video);

    double paint(bool video, bool first_frame = false);
    void paint_layer(const cv::Mat& reference_image, const std::unique_ptr<Brush>& brush, bool refresh, bool random);

    cv::Mat difference(const cv::Mat& reference_image);
    double frame_difference(const cv::Range& xrange, const cv::Range& yrange);

    cv::Mat& frame();
    cv::Mat& prev_frame();
    cv::Mat& prev_source();
    cv::Rect& bounds();

    std::vector<std::unique_ptr<Brush>> _brushes;
    cv::Mat _frame;
    cv::Mat _prev_frame;
    cv::Mat _source;
    cv::Mat _prev_source;
    cv::Rect _bounds;

    Style _style;
};
#endif
