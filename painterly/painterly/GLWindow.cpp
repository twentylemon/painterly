#include "GLWindow.h"

#include <qfiledialog.h>
#include <qmessagebox.h>

#include "Painterly.h"
#include "DotBrush.h"

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

void GLWindow::openImage() {
    painter()->clear_brushes();
    painter()->add_brush(new DotBrush(8));
    painter()->add_brush(new DotBrush(4));
    painter()->add_brush(new DotBrush(2));
    painter()->paint(QFileDialog::getOpenFileName(this, tr("Open Image")).toStdString());
}

void GLWindow::saveImage() {
}
