#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QStringList>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

    loadBoxes();

}

MainWindow::~MainWindow()
{
    delete ui;
}

#define SIZE_SHOP_LIST 8

/*----------------------------------------------------*/

void MainWindow::loadBoxes() {
    QStringList strList;

    QString shop_list[SIZE_SHOP_LIST][4] = {
        {"AOC", "Монитор", "18990", ""},
        {"4TECH", "Мышь", "2600", ""},
        {"4TECH", "Клавиатура", "4990", ""},
        {"WD", "Жёсткий диск", "6800", ""},
        {"MSI", "Видеокарта", "43900", ""},
        {"DEXP", "Звуковая карта", "2300", ""},
        {"KINGSTON", "Оперативная память", "4300", ""},
        {"ASUS", "Материнска плата", "8900", ""}
    };

    for (int i = 0; i < SIZE_SHOP_LIST; i++) {
        strList << shop_list[i][1];
    }

    ui->listWidget->addItems(strList);
    QListWidgetItem* item = 0;
    for(int i = 0; i < ui->listWidget->count(); ++i){
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
}



