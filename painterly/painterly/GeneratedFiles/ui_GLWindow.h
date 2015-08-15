/********************************************************************************
** Form generated from reading UI file 'GLWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLWINDOW_H
#define UI_GLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLWindowClass
{
public:
    QWidget *centralWidget;
    QOpenGLWidget *openGLWidget;
    QPushButton *openImageButton;
    QPushButton *quitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GLWindowClass)
    {
        if (GLWindowClass->objectName().isEmpty())
            GLWindowClass->setObjectName(QStringLiteral("GLWindowClass"));
        GLWindowClass->resize(557, 400);
        centralWidget = new QWidget(GLWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 0, 441, 371));
        openImageButton = new QPushButton(centralWidget);
        openImageButton->setObjectName(QStringLiteral("openImageButton"));
        openImageButton->setGeometry(QRect(460, 10, 75, 23));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(460, 300, 75, 23));
        GLWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GLWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 557, 21));
        GLWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GLWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GLWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GLWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GLWindowClass->setStatusBar(statusBar);

        retranslateUi(GLWindowClass);

        QMetaObject::connectSlotsByName(GLWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *GLWindowClass)
    {
        GLWindowClass->setWindowTitle(QApplication::translate("GLWindowClass", "GLWindow", 0));
        openImageButton->setText(QApplication::translate("GLWindowClass", "Open Image", 0));
        quitButton->setText(QApplication::translate("GLWindowClass", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class GLWindowClass: public Ui_GLWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLWINDOW_H
