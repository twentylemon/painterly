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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLWindowClass
{
public:
    QAction *actionOpen_Image;
    QAction *actionQuit;
    QAction *actionSave_Image;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *buttonOpen_Video;
    QPushButton *buttonQuit;
    QPushButton *buttonSave_Image;
    QPushButton *buttonOpen_Image;
    QLCDNumber *lcdTime_Taken;
    QPushButton *buttonSave_Default;
    QLabel *labelTime_Taken;
    QPushButton *buttonOpen_Chaika;
    QPushButton *buttonRepaint;
    QPushButton *buttonOpen_GoT;
    QPushButton *buttonOpen_Good_Eats;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GLWindowClass)
    {
        if (GLWindowClass->objectName().isEmpty())
            GLWindowClass->setObjectName(QStringLiteral("GLWindowClass"));
        GLWindowClass->resize(301, 237);
        actionOpen_Image = new QAction(GLWindowClass);
        actionOpen_Image->setObjectName(QStringLiteral("actionOpen_Image"));
        actionQuit = new QAction(GLWindowClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSave_Image = new QAction(GLWindowClass);
        actionSave_Image->setObjectName(QStringLiteral("actionSave_Image"));
        centralWidget = new QWidget(GLWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 281, 170));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonOpen_Video = new QPushButton(layoutWidget);
        buttonOpen_Video->setObjectName(QStringLiteral("buttonOpen_Video"));

        gridLayout->addWidget(buttonOpen_Video, 0, 2, 1, 1);

        buttonQuit = new QPushButton(layoutWidget);
        buttonQuit->setObjectName(QStringLiteral("buttonQuit"));
        buttonQuit->setFlat(false);

        gridLayout->addWidget(buttonQuit, 5, 1, 1, 1);

        buttonSave_Image = new QPushButton(layoutWidget);
        buttonSave_Image->setObjectName(QStringLiteral("buttonSave_Image"));

        gridLayout->addWidget(buttonSave_Image, 1, 0, 1, 1);

        buttonOpen_Image = new QPushButton(layoutWidget);
        buttonOpen_Image->setObjectName(QStringLiteral("buttonOpen_Image"));

        gridLayout->addWidget(buttonOpen_Image, 0, 0, 1, 1);

        lcdTime_Taken = new QLCDNumber(layoutWidget);
        lcdTime_Taken->setObjectName(QStringLiteral("lcdTime_Taken"));
        lcdTime_Taken->setEnabled(true);
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        lcdTime_Taken->setPalette(palette);
        lcdTime_Taken->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdTime_Taken, 1, 1, 2, 1);

        buttonSave_Default = new QPushButton(layoutWidget);
        buttonSave_Default->setObjectName(QStringLiteral("buttonSave_Default"));

        gridLayout->addWidget(buttonSave_Default, 4, 0, 1, 1);

        labelTime_Taken = new QLabel(layoutWidget);
        labelTime_Taken->setObjectName(QStringLiteral("labelTime_Taken"));

        gridLayout->addWidget(labelTime_Taken, 0, 1, 1, 1);

        buttonOpen_Chaika = new QPushButton(layoutWidget);
        buttonOpen_Chaika->setObjectName(QStringLiteral("buttonOpen_Chaika"));

        gridLayout->addWidget(buttonOpen_Chaika, 3, 0, 1, 1);

        buttonRepaint = new QPushButton(layoutWidget);
        buttonRepaint->setObjectName(QStringLiteral("buttonRepaint"));

        gridLayout->addWidget(buttonRepaint, 2, 0, 1, 1);

        buttonOpen_GoT = new QPushButton(layoutWidget);
        buttonOpen_GoT->setObjectName(QStringLiteral("buttonOpen_GoT"));

        gridLayout->addWidget(buttonOpen_GoT, 3, 2, 1, 1);

        buttonOpen_Good_Eats = new QPushButton(layoutWidget);
        buttonOpen_Good_Eats->setObjectName(QStringLiteral("buttonOpen_Good_Eats"));

        gridLayout->addWidget(buttonOpen_Good_Eats, 4, 2, 1, 1);

        GLWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GLWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 301, 21));
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
        QObject::connect(actionOpen_Image, SIGNAL(triggered()), GLWindowClass, SLOT(openImage()));
        QObject::connect(actionSave_Image, SIGNAL(triggered()), GLWindowClass, SLOT(saveImage()));
        QObject::connect(buttonOpen_Image, SIGNAL(clicked()), GLWindowClass, SLOT(openImage()));
        QObject::connect(buttonSave_Image, SIGNAL(clicked()), GLWindowClass, SLOT(saveImage()));
        QObject::connect(buttonOpen_Chaika, SIGNAL(clicked()), GLWindowClass, SLOT(openChaika()));
        QObject::connect(buttonSave_Default, SIGNAL(clicked()), GLWindowClass, SLOT(saveDefault()));
        QObject::connect(buttonRepaint, SIGNAL(clicked()), GLWindowClass, SLOT(repaintCurrent()));
        QObject::connect(buttonOpen_Video, SIGNAL(clicked()), GLWindowClass, SLOT(openVideo()));
        QObject::connect(buttonOpen_GoT, SIGNAL(clicked()), GLWindowClass, SLOT(openGoT()));
        QObject::connect(buttonOpen_Good_Eats, SIGNAL(clicked()), GLWindowClass, SLOT(openGoodEats()));

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
        buttonOpen_Video->setText(QApplication::translate("GLWindowClass", "Open Video", 0));
        buttonQuit->setText(QApplication::translate("GLWindowClass", "Quit", 0));
        buttonSave_Image->setText(QApplication::translate("GLWindowClass", "Save Image", 0));
        buttonOpen_Image->setText(QApplication::translate("GLWindowClass", "Open Image", 0));
        buttonSave_Default->setText(QApplication::translate("GLWindowClass", "Save Default", 0));
        labelTime_Taken->setText(QApplication::translate("GLWindowClass", "Time Taken", 0));
        buttonOpen_Chaika->setText(QApplication::translate("GLWindowClass", "Open Chaika", 0));
        buttonRepaint->setText(QApplication::translate("GLWindowClass", "Repaint", 0));
        buttonOpen_GoT->setText(QApplication::translate("GLWindowClass", "Open GoT", 0));
        buttonOpen_Good_Eats->setText(QApplication::translate("GLWindowClass", "Open Good Eats", 0));
        menuFile->setTitle(QApplication::translate("GLWindowClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class GLWindowClass: public Ui_GLWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLWINDOW_H
