

#include "GLWindow.h"

#include "DotBrush.h"
#include "LineBrush.h"
#include "SplineBrush.h"

/*
    TODO
        add brush window; select type and radius
        select predefined styles from paper
        remove brush dropdown
        open/save video
*/

GLWindow::GLWindow(QWidget *parent)
    : QMainWindow(parent), _painter(new Painterly()), _current_image("D:/pics/39.jpg")
{
    ui.setupUi(this);
}

GLWindow::~GLWindow()
{
}


std::unique_ptr<Painterly>& GLWindow::painter() {
    return _painter;
}

const std::unique_ptr<Painterly>& GLWindow::painter() const {
    return _painter;
}


void GLWindow::open_image(const std::string& file) {
    painter()->clear_brushes();
    painter()->add_brush(new SplineBrush(8));
    painter()->add_brush(new SplineBrush(4));
    painter()->add_brush(new SplineBrush(2));
    double time = painter()->paint(file);
    ui.lcdTime_Taken->display(time);
}

void GLWindow::save_image(const std::string& file) {
    painter()->save_canvas(file);
}


void GLWindow::open_video(cv::VideoCapture& video, const std::string& out_file) {
    painter()->clear_brushes();
    painter()->add_brush(new SplineBrush(8));
    painter()->add_brush(new SplineBrush(4));
    painter()->add_brush(new SplineBrush(2));
    double time = painter()->paint(video, out_file);
    ui.lcdTime_Taken->display(time);
}
