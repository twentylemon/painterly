#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <memory>
#include <QtWidgets/QMainWindow>
#include "ui_GLWindow.h"

class Painterly;

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

private:
    void open_image(const std::string& file);
    void save_image(const std::string& file);

    Ui::GLWindowClass ui;
    std::unique_ptr<Painterly> _painter;
};

#endif // GLWINDOW_H
