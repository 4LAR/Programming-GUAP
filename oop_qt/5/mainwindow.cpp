#include "mainwindow.h"
#include "ui_mainwindow.h"

QList <int> vvod,vivod,buffer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    variant = new Variant(this);

    connect(ui->pushButton_4, SIGNAL(clicked(bool)),this,SLOT(zadanie_1()));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)),this,SLOT(zadanie_2()));

    connect(this, &MainWindow::variantSignal, variant, &Variant::variantSlot);

    connect(ui->pushButton, SIGNAL(clicked(bool)),this,SLOT(SearchToIndex()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)),this,SLOT(DeleteToIndex()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)),this,SLOT(DeleteToCount()));
    connect(ui->pushButton_7, SIGNAL(clicked(bool)),this,SLOT(add_el()));
    connect(ui->pushButton_8, SIGNAL(clicked(bool)),this,SLOT(summ_el()));
    connect(ui->pushButton_9, SIGNAL(clicked(bool)),this,SLOT(summ_chet()));
    connect(ui->pushButton_10 ,SIGNAL(clicked(bool)),this,SLOT(readFile()));
    connect(ui->pushButton_11, SIGNAL(clicked(bool)),this,SLOT(writeFile()));
    connect(ui->pushButton_12, SIGNAL(clicked(bool)),this,SLOT(clear_collection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile()
{
    vvod.clear();
    QStringList slist;
    //Имя файла

    QString buf = ui->line_file_name->text();
    buf = buf + ".txt";
    qDebug() << buf;
    QFile file;
    file.setFileName(buf);
    QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
    if (!file.open(QIODevice::ReadOnly)){ // Проверяем, возможно ли открыть наш файл для чтения
        qDebug() <<QDir::currentPath();
        return;
    }// если это сделать невозможно, то завершаем функцию
    data = file.readAll(); //считываем все данные с файла в объект data
    QString input = QString(data);
    slist = input.split(" ");
    bool allOk(true);
    bool ok;
    for (int x = 0; x <= slist.count()-1 && allOk; x++) {
        vvod.append(slist.at(x).toInt(&ok));
        allOk &= ok;
    }
    //вывод файла на экран
    ui->listWidget->clear();
    for (int x = 0; x <= vvod.count()-1; x++) {
       QString g = QString::number(vvod.value(x));
       ui->listWidget->addItem(g);
    }
    buffer = vvod;

}

void MainWindow::writeFile()
{
    QFile file;
    QTextStream stream;
    stream.setDevice(&file);
    QString buf = ui->line_file_name->text();
    buf = buf + ".txt";
    qDebug() << buf;
    file.setFileName(buf);
    file.open(QIODevice::ReadWrite);
    for (int x = 0; x <= vivod.count()-1; x++) {
         if (x!=vivod.count()-1){
             stream << QString::number(vivod.value(x));
             stream << " ";
         }
         else {
             stream << QString::number(vivod.value(x));
         }

    }
    file.close();
}

void MainWindow::clear_collection()
{
    buffer = vvod;
    vivod = vvod;
    ui->listWidget_2->clear();
}

void MainWindow::summ_el()
{
    int sum = 0;
    for (int x = 0; x <= vvod.count()-1; x++) {
        sum += vvod.value(x);
    }
    ui->lineEdit_4->setText(QString::number(sum));
}

void MainWindow::summ_chet()
{
    int sum = 0;
    for (int x = 0; x <= vvod.count()-1; x++) {
        if(x%2!=0) {
            sum += vvod.value(x);
        }
    }
    ui->lineEdit_4->setText(QString::number(sum));
}

void MainWindow::add_el()
{
    ui->listWidget_2->clear();
    QString buf;
    buf = ui->lineEdit_3->text();
    PrintOld();
    buffer.push_back(buf.toInt());
    PrintNew();
    ui->lineEdit_3->clear();


}

void MainWindow::PrintNew()
{
    ui->listWidget_2->clear();
    for (int x = 0; x <= buffer.count()-1; x++) {
       QString g = QString::number(buffer.value(x));
       ui->listWidget_2->addItem(g);
    }
    vivod = buffer;
}

void MainWindow::PrintOld()
{
    ui->listWidget->clear();
    vvod = buffer;
    for (int x = 0; x <= vvod.count()-1; x++) {
       QString g = QString::number(vvod.value(x));
       ui->listWidget->addItem(g);
    }
}

void MainWindow::SearchToIndex()
{
    QString buf = ui->lineEdit->text();
    int index = buf.toInt();
    for (int x = 0; x <= vvod.count()-1; x++) {
        if(x==index) {
            ui->lineEdit_3->setText(QString::number(vvod.value(x)));
        }
    }
    ui->lineEdit->clear();
}

void MainWindow::DeleteToIndex()
{
    QString buf = ui->lineEdit->text();
    PrintOld();
    buffer = vvod;
    buffer.removeAt(buf.toInt());
    ui->lineEdit->clear();
    PrintNew();
}

void MainWindow::DeleteToCount()
{
    QString buf = ui->lineEdit_3->text();
    PrintOld();
    buffer = vvod;
    int number =  buf.toInt();
    for (int x = 0; x <= buffer.count()-1; x++) {
        if(buffer.value(x)==number) {
            buffer.removeAt(x);
        }
    }
    ui->lineEdit_3->clear();
    PrintNew();
}

void MainWindow::zadanie_1() {
    vivod.clear();
    auto iter1 = vvod.begin();
    auto iter2 = vvod.begin();
    int i, j = 0;

    while(iter2 != vvod.end()) {
        if (i % 2 != 0) {
            vivod.push_back(*iter2);
        }

        iter2++;
        i++;
    }

    qDebug() << "--------------------";

    while(iter1 != vvod.end()) {
        if (j % 2 == 0) {
            vivod.push_back(*iter1);
        }

        iter1++;
        j++;

    }

    buffer = vivod;
    PrintNew();
}

void MainWindow::zadanie_2() {
    auto iter1 = vvod.begin();
    auto iter2 = --vvod.end();
    int sum = 0;
    while(iter1 != vvod.end()) {
        if(*iter1 < 0) {
            break;
        }
        else {
            ++iter1;
        }
    }
    if (iter1 == vvod.end()) {
        ui->lineEdit_4->setText("Нет отр.");
    } else {
        for(auto x = ++iter1 - 1; x != vvod.end(); x++) {
            sum += qFabs(*x);
        }

        ui->lineEdit_4->setText(QString::number(sum));
    }

}


