
#ifndef STYLE_H
#define STYLE_H

#include <array>

class Style
{
public:
    Style();

    void impressionist();
    void expressionist();
    void colorish_wash();
    void pointillist();

    double threshold() const;
    void set_threshold(double threshold);

    double video_threshold() const;
    void set_video_threshold(double video_threshold);

    double blur_factor() const;
    void set_blur_factor(double blur_factor);

    double grid_size() const;
    void set_grid_size(double grid_size);

    double alpha() const;
    void set_alpha(double alpha);

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

private:
    double _approx_threshold;
    double _video_threshold;
    double _blur_factor;
    double _grid_size;
    double _alpha;
    std::array<double,3> _rgb_jitter;
    std::array<double,3> _hsv_jitter;
};
#endif
