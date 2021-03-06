

#include "GLWindow.h"

#include "DotBrush.h"
#include "LineBrush.h"
#include "SplineBrush.h"

#include <qfiledialog.h>

void GLWindow::openChaika() {
    open_image("D:/pics/39.jpg");
}

void GLWindow::openImage() {
    _current_image = QFileDialog::getOpenFileName(this, "Open Image").toStdString();
    repaintCurrent();
}

void GLWindow::saveDefault() {
    save_image("D:/pics/out.jpg");
}

void GLWindow::saveImage() {
    save_image(QFileDialog::getSaveFileName(this, "Save Image").toStdString());
}

void GLWindow::repaintCurrent() {
    open_image(_current_image);
}


void GLWindow::openVideo() {
    cv::VideoCapture video(QFileDialog::getOpenFileName(this, "Open Video").toStdString());
    open_video(video, "D:/vids/out.avi");
}

void GLWindow::openGoT() {
    cv::VideoCapture video("D:/vids/got_short.mp4");
    open_video(video, "D:/vids/got.avi");
}

void GLWindow::openGoodEats() {
    cv::VideoCapture video("D:/vids/Good Eats/Couch Potato Weekend (Potato Interstitials)/Couch Potato Weekend - A Spud In Every Tank.mp4");
    open_video(video, "D:/vids/good_eats.avi");
}

void GLWindow::openWebcam() {
    cv::VideoCapture cam(0);
    open_video(cam, "D:/vids/cam.avi");
}
