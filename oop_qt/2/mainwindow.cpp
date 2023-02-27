#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QStringList>
#include <QListWidgetItem>
#include <QListWidgetItem>
#include <QPixmap>
#include <QFile>
#include <QDir>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

    //ui->pushButton->setHidden(true);

    loadBoxes();
    loadImages();
    generate_price(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*----------------------------------------------------*/

#define SIZE_SHOP_LIST 8

QString shop_list[SIZE_SHOP_LIST][4] = {
    {"AOC", "Монитор", "18990", "0"},
    {"4TECH", "Мышь", "2600", "0"},
    {"4TECH", "Клавиатура", "4990", "0"},
    {"WD", "Жёсткий_диск", "6800", "0"},
    {"MSI", "Видеокарта", "43900", "0"},
    {"DEXP", "Звуковая_карта", "2300", "0"},
    {"KINGSTON", "Оперативная_память", "4300", "0"},
    {"ASUS", "Материнска_плата", "8900", "0"}
};

#define DISCOUNT 10

/*----------------------------------------------------*/

void MainWindow::generate_price(bool save_check = false) {

    QStringList List;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < SIZE_SHOP_LIST; i++) {
        if (shop_list[i][3].toInt() > 0) {
            count++;
        }
    }

    if (count < 1) {
        if (count == 0) {
            id_main = -1;
        }
        List << "Пусто";
    }

    if (id_main != -1) {
        List << "Основной товар: " << shop_list[id_main][2] + " = " + shop_list[id_main][0] + " " + shop_list[id_main][1];
    }

    if (count > 1) {
        List << "Дополнительные товары: ";
    }
    for (int i = 0; i < SIZE_SHOP_LIST; i++) {
        if (shop_list[i][3].toInt() > 0 && id_main != i) {
            List << shop_list[i][2] + " = " + shop_list[i][0] + " " + shop_list[i][1];
            sum += shop_list[i][2].toInt();
        }
    }


    List << "--------";
    if (count == SIZE_SHOP_LIST) {
        List << "Скидка на доп. товары: " + QString::number(DISCOUNT) + "%";
        List << "Без скидки на доп. товары: " + QString::number(sum) + "руб";
        List << "Итог: " + QString::number(sum - (((sum - shop_list[id_main][2].toInt()) / 100) * DISCOUNT)) + "руб";
    } else {
        List << "Итог: " + QString::number(sum) + "руб";
    }

    model->setStringList(List);
    ui->listView->setModel(model);

    // сохранение файла
    if (save_check) {

        QString filename = "check.txt";
        QFile file(filename);
        if (file.open(QFile::WriteOnly|QFile::Truncate)) {
            QTextStream stream(&file);
            for (int i = 0; i < List.size(); ++i)
                stream << List.at(i) << '\n';
        }
    }
}

int MainWindow::get_id(QString name) {
    for (int i = 0; i < SIZE_SHOP_LIST; i++) {
        if (name == shop_list[i][1]) {
            return i;
        }
    }
    return -1;
}

void MainWindow::update_count(QString name, int count) {
    for (int i = 0; i < SIZE_SHOP_LIST; i++) {
        if (name == shop_list[i][1]) {
            if ((count == 1 && shop_list[i][3] == "0") || (count == -1 && shop_list[i][3] == "1"))
                shop_list[i][3] = QString::number(shop_list[i][3].toInt() + count);
            break;
        }
    }
}

void MainWindow::test(QListWidgetItem *item){
//    if (item->checkState() == Qt::Checked)
//        item->setCheckState(Qt::Unchecked);
//    else
//        item->setCheckState(Qt::Checked);

    QString name = item->text().split(" ")[1];

    if (id_main == -1) {
        id_main = get_id(name);
    }

    if (item->checkState() == Qt::Checked) {
        update_count(name, 1);
    } else {
        update_count(name, -1);
    }
    generate_price();

}


void MainWindow::loadBoxes() {
    QStringList strList;

    for (int i = 0; i < SIZE_SHOP_LIST; i++) {
        strList << shop_list[i][0] + " " + shop_list[i][1] + " (" + shop_list[i][2] + "руб)";
    }

    ui->listWidget->addItems(strList);
    QListWidgetItem* item = 0;
    for(int i = 0; i < ui->listWidget->count(); ++i){
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem *)), SLOT(test(QListWidgetItem *)));
}

void MainWindow::loadImages() {
    //QPixmap myPixmap( ":/img/logo.png" );
    //ui->label->setPixmap( myPixmap );
}


/*----------------------------------------------------*/

void MainWindow::on_pushButton_2_clicked() {
    generate_price(true);
}
