#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <memory>
#include <QtWidgets/QMainWindow>
#include "ui_GLWindow.h"
#include "Painterly.h"

class GLWindow : public QMainWindow
{
    Q_OBJECT

public:
    GLWindow(QWidget *parent = 0);
    ~GLWindow();
    
    std::unique_ptr<Painterly>& painter();
    const std::unique_ptr<Painterly>& painter() const;

private slots:
    void saveImage();
    void openImage();
    void saveDefault();
    void openChaika();
    void repaintCurrent();

    void openVideo();
    void openDefaultVideo();

private:
    void open_image(const std::string& file);
    void save_image(const std::string& file);
    void paint();

    void open_video(cv::VideoCapture& video, const std::string& out_file);

    Ui::GLWindowClass ui;
    std::unique_ptr<Painterly> _painter;
    std::string _current_image;
};

#endif // GLWINDOW_H
