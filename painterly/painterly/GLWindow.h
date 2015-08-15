#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_GLWindow.h"

class GLWindow : public QMainWindow
{
    Q_OBJECT

public:
    GLWindow(QWidget *parent = 0);
    ~GLWindow();

private:
    Ui::GLWindowClass ui;
};

#endif // GLWINDOW_H
