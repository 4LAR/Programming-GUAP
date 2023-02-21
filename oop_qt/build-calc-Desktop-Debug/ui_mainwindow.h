/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QListView *listView;
    QPushButton *pushButton;
    QLabel *label;
    QFrame *line;
    QLineEdit *lineEdit_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(464, 296);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 241, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 10, 111, 20));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 10, 31, 20));
        lineEdit_2->setLayoutDirection(Qt::RightToLeft);
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_2->setReadOnly(true);
        listView = new QListView(widget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(270, 50, 181, 191));
        listView->setLayoutDirection(Qt::RightToLeft);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(390, 10, 61, 31));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 20, 58, 18));
        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(250, -20, 20, 291));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 10, 101, 20));
        lineEdit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_3->setReadOnly(true);
        MainWindow->setCentralWidget(widget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 464, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "KALculator", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
