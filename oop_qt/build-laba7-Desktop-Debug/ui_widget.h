/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *ageLabel;
    QLabel *estateTypeLabel;
    QLabel *residetnsLabel;
    QLabel *areaLabel;
    QLabel *periodLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QComboBox *estateTypeBox;
    QLineEdit *residentsEdit;
    QLineEdit *areaEdit;
    QComboBox *periodBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *costLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *calcButton;
    QPushButton *undoButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(521, 272);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Widget->setFont(font);
        Widget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        nameLabel = new QLabel(Widget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Rockwell Nova"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        nameLabel->setFont(font1);
        nameLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(nameLabel);

        ageLabel = new QLabel(Widget);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));
        ageLabel->setEnabled(true);
        ageLabel->setFont(font1);
        ageLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(ageLabel);

        estateTypeLabel = new QLabel(Widget);
        estateTypeLabel->setObjectName(QString::fromUtf8("estateTypeLabel"));
        estateTypeLabel->setFont(font1);
        estateTypeLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(estateTypeLabel);

        residetnsLabel = new QLabel(Widget);
        residetnsLabel->setObjectName(QString::fromUtf8("residetnsLabel"));
        residetnsLabel->setFont(font1);
        residetnsLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(residetnsLabel);

        areaLabel = new QLabel(Widget);
        areaLabel->setObjectName(QString::fromUtf8("areaLabel"));
        areaLabel->setFont(font1);
        areaLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(areaLabel);

        periodLabel = new QLabel(Widget);
        periodLabel->setObjectName(QString::fromUtf8("periodLabel"));
        periodLabel->setFont(font1);
        periodLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(periodLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nameEdit = new QLineEdit(Widget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setFont(font1);
        nameEdit->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(nameEdit);

        ageEdit = new QLineEdit(Widget);
        ageEdit->setObjectName(QString::fromUtf8("ageEdit"));
        ageEdit->setFont(font1);
        ageEdit->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(ageEdit);

        estateTypeBox = new QComboBox(Widget);
        estateTypeBox->addItem(QString());
        estateTypeBox->addItem(QString());
        estateTypeBox->addItem(QString());
        estateTypeBox->addItem(QString());
        estateTypeBox->setObjectName(QString::fromUtf8("estateTypeBox"));
        estateTypeBox->setFont(font1);
        estateTypeBox->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(estateTypeBox);

        residentsEdit = new QLineEdit(Widget);
        residentsEdit->setObjectName(QString::fromUtf8("residentsEdit"));
        residentsEdit->setFont(font1);
        residentsEdit->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(residentsEdit);

        areaEdit = new QLineEdit(Widget);
        areaEdit->setObjectName(QString::fromUtf8("areaEdit"));
        areaEdit->setFont(font1);
        areaEdit->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(areaEdit);

        periodBox = new QComboBox(Widget);
        periodBox->addItem(QString());
        periodBox->addItem(QString());
        periodBox->addItem(QString());
        periodBox->setObjectName(QString::fromUtf8("periodBox"));
        periodBox->setFont(font1);
        periodBox->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(periodBox);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        costLabel = new QLabel(Widget);
        costLabel->setObjectName(QString::fromUtf8("costLabel"));
        costLabel->setFont(font1);
        costLabel->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(costLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        calcButton = new QPushButton(Widget);
        calcButton->setObjectName(QString::fromUtf8("calcButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calcButton->sizePolicy().hasHeightForWidth());
        calcButton->setSizePolicy(sizePolicy);
        calcButton->setFont(font1);
        calcButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(calcButton);

        undoButton = new QPushButton(Widget);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));
        undoButton->setFont(font1);
        undoButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(undoButton);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\320\241\321\202\320\276\320\273\321\217\321\200\320\276\320\262 \320\235\320\270\320\272\320\270\321\202\320\260 4134\320\232", nullptr));
        nameLabel->setText(QCoreApplication::translate("Widget", "\320\230\320\274\321\217:", nullptr));
        ageLabel->setText(QCoreApplication::translate("Widget", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202:", nullptr));
        estateTypeLabel->setText(QCoreApplication::translate("Widget", "\320\232\320\273\320\260\321\201\321\201 \320\266\320\270\320\273\321\214\321\217:", nullptr));
        residetnsLabel->setText(QCoreApplication::translate("Widget", "\320\247\320\270\321\201\320\273\320\276 \320\277\321\200\320\276\320\266\320\270\320\262\320\260\321\216\321\211\320\270\321\205:", nullptr));
        areaLabel->setText(QCoreApplication::translate("Widget", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214:", nullptr));
        periodLabel->setText(QCoreApplication::translate("Widget", "\320\241\321\200\320\276\320\272 \321\201\321\202\321\200\320\260\321\205\320\276\320\262\320\260\320\275\320\270\321\217: ", nullptr));
        nameEdit->setText(QString());
        nameEdit->setPlaceholderText(QString());
        ageEdit->setText(QString());
        ageEdit->setPlaceholderText(QString());
        estateTypeBox->setItemText(0, QCoreApplication::translate("Widget", "\320\232\320\262\320\260\321\200\321\202\320\270\321\200\320\260 \321\215\320\272\320\276\320\275\320\276\320\274-\320\272\320\273\320\260\321\201\321\201\320\260", nullptr));
        estateTypeBox->setItemText(1, QCoreApplication::translate("Widget", "\320\255\320\273\320\270\321\202\320\275\320\260\321\217 \320\272\320\262\320\260\321\200\321\202\320\270\321\200\320\260", nullptr));
        estateTypeBox->setItemText(2, QCoreApplication::translate("Widget", "\320\242\320\260\321\203\320\275-\321\205\320\260\321\203\321\201", nullptr));
        estateTypeBox->setItemText(3, QCoreApplication::translate("Widget", "\320\232\320\276\321\202\321\202\320\265\320\264\320\266", nullptr));

        residentsEdit->setText(QString());
        residentsEdit->setPlaceholderText(QString());
        areaEdit->setText(QString());
        areaEdit->setPlaceholderText(QString());
        periodBox->setItemText(0, QCoreApplication::translate("Widget", "6 \320\274\320\265\321\201\321\217\321\206\320\265\320\262 ", nullptr));
        periodBox->setItemText(1, QCoreApplication::translate("Widget", "12 \320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        periodBox->setItemText(2, QCoreApplication::translate("Widget", "18 \320\274\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));

        costLabel->setText(QCoreApplication::translate("Widget", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 \320\262\320\267\320\275\320\276\321\201\320\260:   0", nullptr));
        calcButton->setText(QCoreApplication::translate("Widget", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        undoButton->setText(QCoreApplication::translate("Widget", "\320\237\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\271 \320\267\320\260\320\277\321\200\320\276\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
