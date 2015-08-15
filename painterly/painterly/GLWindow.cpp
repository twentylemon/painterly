#include "GLWindow.h"

#include <qfiledialog.h>
#include <qmessagebox.h>

GLWindow::GLWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

GLWindow::~GLWindow()
{

}

void GLWindow::openImage() {
    QString file = QFileDialog::getOpenFileName(this, tr("Open Image"));
    QMessageBox::information(this, tr("file"), file);
}

void GLWindow::saveImage() {
}
