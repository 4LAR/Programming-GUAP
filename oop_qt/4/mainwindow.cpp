#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

//   setStyleSheet("background-color: #D3D3D3;");

    ui->setupUi(this);
    setWindowTitle("Photo");
    connect(ui->pushButton_end, &QPushButton::clicked, this, &MainWindow::calculatePrice);

}

MainWindow::~MainWindow()
{
    delete ui;
}

float price_item = 0;
float price_material = 0;
double pol;




//------------------------------------------------------//
void MainWindow::on_radioButton_col_clicked(bool checked)
{
    if(checked)
    {
       price_item = 1000;
    }
    ui->label_totalPrice->clear();
}
void MainWindow::on_radioButton_bras_clicked(bool checked)
{
    if(checked)
    {
      price_item = 2000;
    }
    ui->label_totalPrice->clear();
}
void MainWindow::on_radioButton_cep_clicked(bool checked)
{
    if(checked)
    {
       price_item = 3000;
    }
    ui->label_totalPrice->clear();
}

//--------------------------------------------------------//

void MainWindow::on_radioButton_iron_clicked(bool checked)
{
    if(checked)
    {
       price_material  = 4;
    }
    ui->label_totalPrice->clear();
}
void MainWindow::on_radioButton_copper_clicked(bool checked)
{
    if(checked)
    {
      price_material = 2;


    }
    ui->label_totalPrice->clear();
}
void MainWindow::on_radioButton_gold_clicked(bool checked)
{
    if(checked)
    {
       price_material = 10;
    }
    ui->label_totalPrice->clear();
}
//

void MainWindow::on_pushButton_end_clicked()
{

}


void MainWindow::calculatePrice()
{

    QString sizeString = ui->lineEdit_size->text();
        if (sizeString.isEmpty() || !sizeString.toDouble())
        {
            ui->label_totalPrice->clear();
            return;
        }

    double size = ui->lineEdit_size->text().toDouble();

    double material_price = ui->radioButton_iron->isChecked() ? 4 :
                            ui->radioButton_copper->isChecked() ? 2 : 0;
//                            ui->radioButton_gold->isChecked() ? 9 : 0;

    double product_price = ui->radioButton_col->isChecked() ? 1000 :
                           ui->radioButton_bras->isChecked() ? 2000 :
                           ui->radioButton_cep->isChecked() ? 3000 : 0;


    double total_price = size * material_price * product_price;
    ui->label_totalPrice->setText(QString::number(total_price));
}

void MainWindow::on_groupBox_2_clicked()
{
    qDebug() << "132";
}


void MainWindow::on_lineEdit_size_textChanged(const QString &arg1)
{
    ui->label_totalPrice->clear();
}

