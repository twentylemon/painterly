#include "GLWindow.h"
#include <QtWidgets/QApplication>

#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GLWindow w;
    w.show();
    return a.exec();
}
