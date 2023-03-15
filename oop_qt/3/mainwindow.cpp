#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QString>
#include <QStringListModel>
#include <QDebug>
#include <QtMath>

#define length_materials 3

int materials[length_materials] = {
//    {"Флис", "200"},
//    {"Хлопок", "400"},
//    {"Лён", "500"}
    200,
    400,
    500
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

    ui->lineEdit_4->setText(QString::number(materials[0]));
    ui->lineEdit->setText(QString::number(1));
    ui->lineEdit_2->setText(QString::number(1));

    connect(
        ui->pushButton,
        &QPushButton::released,
        this,
        [this]{calculate(); });

}

void MainWindow::calculate() {
    int current_index = ui->comboBox->currentIndex();
//    ui->lineEdit;
//    ui->lineEdit_2;
//    ui->lineEdit_4;
    //.toDouble()
    double width = ui->lineEdit->text().toDouble();
    double height = ui->lineEdit_2->text().toDouble();
    ui->lineEdit_3->setText(
       QString::number(width * height * materials[current_index])
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->lineEdit_4->setText(QString::number(materials[index]));
    ui->lineEdit_3->clear();
}

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
//    ui->lineEdit_3->text();
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
//    ui->lineEdit_3->text();
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->lineEdit_3->clear();
}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->lineEdit_3->clear();
}

