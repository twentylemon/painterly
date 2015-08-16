

#include "GLWindow.h"

#include "Painterly.h"
#include "DotBrush.h"

/*
    TODO
        add brush window; select type and radius
        select predefined styles from paper
        remove brush dropdown
        open/save video
*/

GLWindow::GLWindow(QWidget *parent)
    : QMainWindow(parent), _painter(new Painterly())
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
    painter()->add_brush(new DotBrush(8));
    painter()->add_brush(new DotBrush(4));
    painter()->add_brush(new DotBrush(2));
    double time = painter()->paint(file);
    ui.lcdTime_Taken->display(time);
}

void GLWindow::save_image(const std::string& file) {
    painter()->save_canvas(file);
}
