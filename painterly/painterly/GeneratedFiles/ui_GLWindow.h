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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLWindowClass
{
public:
    QAction *actionOpen_Image;
    QAction *actionQuit;
    QAction *actionSave_Image;
    QWidget *centralWidget;
    QPushButton *buttonQuit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonOpen_Image;
    QPushButton *buttonSave_Image;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GLWindowClass)
    {
        if (GLWindowClass->objectName().isEmpty())
            GLWindowClass->setObjectName(QStringLiteral("GLWindowClass"));
        GLWindowClass->resize(261, 264);
        actionOpen_Image = new QAction(GLWindowClass);
        actionOpen_Image->setObjectName(QStringLiteral("actionOpen_Image"));
        actionQuit = new QAction(GLWindowClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSave_Image = new QAction(GLWindowClass);
        actionSave_Image->setObjectName(QStringLiteral("actionSave_Image"));
        centralWidget = new QWidget(GLWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        buttonQuit = new QPushButton(centralWidget);
        buttonQuit->setObjectName(QStringLiteral("buttonQuit"));
        buttonQuit->setGeometry(QRect(90, 180, 75, 23));
        buttonQuit->setFlat(false);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 77, 54));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        buttonOpen_Image = new QPushButton(layoutWidget);
        buttonOpen_Image->setObjectName(QStringLiteral("buttonOpen_Image"));

        verticalLayout->addWidget(buttonOpen_Image);

        buttonSave_Image = new QPushButton(layoutWidget);
        buttonSave_Image->setObjectName(QStringLiteral("buttonSave_Image"));

        verticalLayout->addWidget(buttonSave_Image);

        GLWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GLWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 261, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        GLWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GLWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GLWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GLWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GLWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_Image);
        menuFile->addAction(actionSave_Image);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(GLWindowClass);
        QObject::connect(actionQuit, SIGNAL(triggered()), GLWindowClass, SLOT(close()));
        QObject::connect(buttonQuit, SIGNAL(clicked()), GLWindowClass, SLOT(close()));
        QObject::connect(buttonOpen_Image, SIGNAL(clicked()), GLWindowClass, SLOT(openImage()));
        QObject::connect(actionOpen_Image, SIGNAL(triggered()), GLWindowClass, SLOT(openImage()));
        QObject::connect(actionSave_Image, SIGNAL(triggered()), GLWindowClass, SLOT(saveImage()));
        QObject::connect(buttonSave_Image, SIGNAL(clicked()), GLWindowClass, SLOT(saveImage()));

        QMetaObject::connectSlotsByName(GLWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *GLWindowClass)
    {
        GLWindowClass->setWindowTitle(QApplication::translate("GLWindowClass", "Painterly Rendering", 0));
        actionOpen_Image->setText(QApplication::translate("GLWindowClass", "Open Image", 0));
        actionOpen_Image->setShortcut(QApplication::translate("GLWindowClass", "Ctrl+O", 0));
        actionQuit->setText(QApplication::translate("GLWindowClass", "Quit", 0));
        actionSave_Image->setText(QApplication::translate("GLWindowClass", "Save Image", 0));
        actionSave_Image->setShortcut(QApplication::translate("GLWindowClass", "Ctrl+S", 0));
        buttonQuit->setText(QApplication::translate("GLWindowClass", "Quit", 0));
        buttonOpen_Image->setText(QApplication::translate("GLWindowClass", "Open Image", 0));
        buttonSave_Image->setText(QApplication::translate("GLWindowClass", "Save Image", 0));
        menuFile->setTitle(QApplication::translate("GLWindowClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class GLWindowClass: public Ui_GLWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLWINDOW_H
