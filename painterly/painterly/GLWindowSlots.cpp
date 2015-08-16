

#include "GLWindow.h"

#include <qfiledialog.h>

void GLWindow::openChaika() {
    open_image("D:/pics/39.jpg");
}

void GLWindow::openImage() {
    open_image(QFileDialog::getOpenFileName(this, "Open Image").toStdString());
}

void GLWindow::saveDefault() {
    save_image("D:/pics/out.jpg");
}

void GLWindow::saveImage() {
    save_image(QFileDialog::getSaveFileName(this, "Save Image").toStdString());
}
