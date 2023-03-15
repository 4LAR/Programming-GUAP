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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_col;
    QRadioButton *radioButton_bras;
    QRadioButton *radioButton_cep;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_iron;
    QRadioButton *radioButton_copper;
    QLineEdit *lineEdit_size;
    QPushButton *pushButton_end;
    QLabel *label_4;
    QLineEdit *label_totalPrice;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(323, 317);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 131, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 30, 91, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 30, 91, 16));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 120, 111));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 89, 80));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_col = new QRadioButton(layoutWidget);
        radioButton_col->setObjectName(QString::fromUtf8("radioButton_col"));

        gridLayout->addWidget(radioButton_col, 0, 0, 1, 1);

        radioButton_bras = new QRadioButton(layoutWidget);
        radioButton_bras->setObjectName(QString::fromUtf8("radioButton_bras"));

        gridLayout->addWidget(radioButton_bras, 1, 0, 1, 1);

        radioButton_cep = new QRadioButton(layoutWidget);
        radioButton_cep->setObjectName(QString::fromUtf8("radioButton_cep"));

        gridLayout->addWidget(radioButton_cep, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(150, 60, 120, 111));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 96, 80));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_iron = new QRadioButton(layoutWidget1);
        radioButton_iron->setObjectName(QString::fromUtf8("radioButton_iron"));

        gridLayout_2->addWidget(radioButton_iron, 0, 0, 1, 1);

        radioButton_copper = new QRadioButton(layoutWidget1);
        radioButton_copper->setObjectName(QString::fromUtf8("radioButton_copper"));

        gridLayout_2->addWidget(radioButton_copper, 1, 0, 1, 1);

        lineEdit_size = new QLineEdit(centralwidget);
        lineEdit_size->setObjectName(QString::fromUtf8("lineEdit_size"));
        lineEdit_size->setGeometry(QRect(120, 180, 113, 22));
        lineEdit_size->setReadOnly(false);
        pushButton_end = new QPushButton(centralwidget);
        pushButton_end->setObjectName(QString::fromUtf8("pushButton_end"));
        pushButton_end->setGeometry(QRect(30, 210, 75, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 180, 131, 16));
        label_totalPrice = new QLineEdit(centralwidget);
        label_totalPrice->setObjectName(QString::fromUtf8("label_totalPrice"));
        label_totalPrice->setGeometry(QRect(120, 210, 113, 22));
        label_totalPrice->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 323, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\202\320\276\320\220\321\202\320\265\320\273\321\214\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \321\204\320\276\321\202\320\276", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\221\321\203\320\274\320\260\320\263\320\260", nullptr));
        groupBox->setTitle(QString());
        radioButton_col->setText(QCoreApplication::translate("MainWindow", "9 \321\205 12", nullptr));
        radioButton_bras->setText(QCoreApplication::translate("MainWindow", "10 \321\205 15", nullptr));
        radioButton_cep->setText(QCoreApplication::translate("MainWindow", "20 \321\205 30", nullptr));
        groupBox_2->setTitle(QString());
        radioButton_iron->setText(QCoreApplication::translate("MainWindow", "\320\263\320\273\321\217\320\275\321\206\320\265\320\262\320\260\321\217", nullptr));
        radioButton_copper->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\276\320\262\320\260\321\217", nullptr));
        pushButton_end->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\204\320\276\321\202\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
