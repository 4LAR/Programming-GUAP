#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget),
      forIntValidator(QRegularExpression("^[0-9]+$")),
      forDoubleValidator(QRegularExpression("^[0-9]*[.]?[0-9]+$")),
      forOwnerValidator(QRegularExpression("^([А-Я][а-я]+)\\s([А-Я][а-яА-Я-]+)$")),
      info(this)
{
    ui->setupUi(this);
    ui->undoButton->setEnabled(false);
    ui->ageEdit->setValidator(&forIntValidator);
    ui->residentsEdit->setValidator(&forIntValidator);
    ui->areaEdit->setValidator(&forDoubleValidator);
    ui->nameEdit->setValidator(&forOwnerValidator);

    connect(&info, SIGNAL(notifyObservers()), this, SLOT(update()));
    connect(ui->calcButton, SIGNAL(pressed()), this, SLOT(calcPressed()));
    connect(ui->undoButton, SIGNAL(pressed()), this, SLOT(undoPressed()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update(){
    auto value = info.getActualData();
    if (value != nullptr) fillForm(value);
    ui->undoButton->setEnabled(info.hasStates());
    value = nullptr;
}

void Widget::calcPressed(){
    try {
    auto value = processForm();
    showCost(value);
    info.add(value);
    ui->undoButton->setEnabled(true);
    value = nullptr;
    //update();
    }
    catch(const myException &error){
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(400,400);

        msg.setText(error.what());
        msg.setText("Заполните поля!         ");
        msg.exec();
        return;
    }
}

void Widget::undoPressed(){
    if (info.getSize() > 1) info.undo();
    else {
        //qInfo() << info.hasStates();
        ui->undoButton->setEnabled(false);
        return;
    }
}

estate *Widget::processForm(){
    return new estate(ui->nameEdit->text(), ui->ageEdit->text().toInt(), ui->estateTypeBox->currentIndex(),
                      ui->residentsEdit->text().toInt(), ui->areaEdit->text().toDouble(), ui->periodBox->currentText());
}

void Widget::fillForm(estate *value){
    ui->nameEdit->setText(info.getActualData()->getOwner());
    ui->ageEdit->setText(QString::number(info.getActualData()->getAge()));
    ui->residentsEdit->setText(QString::number(info.getActualData()->getResidents()));
    ui->periodBox->setCurrentIndex((info.getActualData()->getMonths() / 6) - 1);
    ui->areaEdit->setText(QString::number(info.getActualData()->getArea()));
    switch (info.getActualData()->getType()){
    case estate::EstateType::ECONOM:
        ui->estateTypeBox->setCurrentIndex(0);
        break;
    case estate::EstateType::LUXURIOUS:
        ui->estateTypeBox->setCurrentIndex(1);
        break;
    case estate::EstateType::TOWN_HOUSE:
        ui->estateTypeBox->setCurrentIndex(2);
        break;
    case estate::EstateType::COTTAGE:
        ui->estateTypeBox->setCurrentIndex(3);
        break;
    }
    showCost(value);
}

void Widget::showCost(estate *value)
{
    ui->costLabel->setText("Стоимость страхового взноса: " + QString::number(calculationFacade::getCost(value)));
}
