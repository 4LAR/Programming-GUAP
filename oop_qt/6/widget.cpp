#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , info(this)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    ui->btnUndo->setEnabled(false);

    // регистрация слушателя
    connect(&info, SIGNAL(notifyObservers()), this, SLOT(update()));//включаем сигнал для наблюдателя
    connect(ui->btnCalc, SIGNAL(pressed()), this, SLOT(btnCalcPressed()));
    connect(ui->btnUndo, SIGNAL(pressed()), this, SLOT(btnUndoPressed()));
}

Widget::~Widget()
{
    delete ui;
}

//public slots
void Widget::update(){
    auto value = info.getActualData();
    if(value != nullptr){
        fillForm(value);
    }
    //update btnUndo state
    ui->btnUndo->setEnabled(info.hasStates());
    //seting value to null
    value=nullptr;
}

//private slots
void Widget::btnCalcPressed(){
    auto value=processForm();
    showCost(value);
    info.add(value);
    ui->btnUndo->setEnabled(info.hasStates());

    //seting value to null
    value=nullptr;
}

void Widget::btnUndoPressed(){
    info.undo();
    //update();
    ui->cost->setText("0");
}

//private
Estate *Widget::processForm(){
    int age = ui->age->text().toInt();
    int area = ui->area->text().toInt();
    int residents = ui->residents->text().toInt();
    int months = ui->period->currentIndex();
    Estate::EstateType type = static_cast<Estate::EstateType>(ui->estateType->currentIndex());
    QString owner = ui->owner->text();
    return new Estate(age, area, residents, months, type, owner );
}

void Widget::fillForm(Estate *value){
    QString str=value->getName();
    ui->owner->setText(str);

    str=QString::number(value->getAge());
    ui->age->setText(str);

    if (value->getType() == Estate::EstateType::ECONOM) {
    ui->estateType->setCurrentIndex(0);
    } else if (value->getType() == Estate::EstateType::LUXURIOUS) {
    ui->estateType->setCurrentIndex(1);
    } else if (value->getType() == Estate::EstateType::TOWN_HOUSE) {
    ui->estateType->setCurrentIndex(2);
    } else if (value->getType() == Estate::EstateType::COTTAGE) {
    ui->estateType->setCurrentIndex(3);
    }

    str=QString::number(value->getResidents());
    ui->residents->setText(str);

    str=QString::number(value->getArea());
    ui->area->setText(str);

    ui->period->setCurrentIndex(value->getMonths());

}
void Widget::showCost(Estate *value){
    CalculationFacade cur;
    int cost=cur.getCost(value);
    QString str=QString::number(cost);
    ui->cost->setText(str);
}

void Widget::on_btnCalc_clicked()
{

}
