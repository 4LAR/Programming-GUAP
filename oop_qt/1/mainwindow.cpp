#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QtMath>

#define CALC_BUTTONS_X 5
#define CALC_BUTTONS_Y 5

#define BUTTONS_STYLE "height: 100px;"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);

    QString CALC_BUTTONS[CALC_BUTTONS_Y][CALC_BUTTONS_X] = {
        {"", "", "", "", "C"},
        {"7", "8", "9", "÷", "√"},
        {"4", "5", "6", "×", "-"},
        {"1", "2", "3", "+", "="},
        {"0", "00", ".", "", ""}
    };
    /*
        0 - символ
        1 - сложить
        2 - вычесть
        3 - умножить
        4 - разделить
        5 - квадратный корень
        6 - удалить
        7 - вычеслить
    */
    int CALC_BUTTONS_CONF[CALC_BUTTONS_Y][CALC_BUTTONS_X][3] = {
        {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 6}},
        {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 4}, {1, 1, 5}},
        {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 3}, {1, 1, 2}},
        {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {2, 1, 1}, {2, 1, 7}},
        {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 0}, {1, 1, 0}},
    };

    QPushButton** buttons = new QPushButton*[CALC_BUTTONS_Y * CALC_BUTTONS_X];

    for (int y = 0; y < CALC_BUTTONS_Y; y++) {
        for (int x = 0; x < CALC_BUTTONS_X; x++) {
            if (CALC_BUTTONS[y][x] != "") {
                buttons[CALC_BUTTONS_Y * y + x] = new QPushButton(CALC_BUTTONS[y][x]);
                ui->gridLayout->addWidget(
                    buttons[CALC_BUTTONS_Y * y + x],
                    y,
                    x,
                    CALC_BUTTONS_CONF[y][x][0],
                    CALC_BUTTONS_CONF[y][x][1]
                );
//                buttons[CALC_BUTTONS_Y * y + x]->setSizeIncrement(10, 10);
                buttons[CALC_BUTTONS_Y * y + x]->setStyleSheet(BUTTONS_STYLE);
                connect(
                    buttons[CALC_BUTTONS_Y * y + x],
                    &QPushButton::released,
                    this,
                    [this, CALC_BUTTONS, x, y, CALC_BUTTONS_CONF]{ button_press(CALC_BUTTONS[y][x], CALC_BUTTONS_CONF[y][x][2]); });

            }
        }
    }



}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {

    // числа
    case(Qt::Key_0):
        button_press("0", 0);
        break;
    case(Qt::Key_1):
        button_press("1", 0);
        break;
    case(Qt::Key_2):
        button_press("2", 0);
        break;
    case(Qt::Key_3):
        button_press("3", 0);
        break;
    case(Qt::Key_4):
        button_press("4", 0);
        break;
    case(Qt::Key_5):
        button_press("5", 0);
        break;
    case(Qt::Key_6):
        button_press("6", 0);
        break;
    case(Qt::Key_7):
        button_press("7", 0);
        break;
    case(Qt::Key_8):
        button_press("8", 0);
        break;
    case(Qt::Key_9):
        button_press("9", 0);
        break;
    //
    case(Qt::Key_Period):
        button_press(".", 0);
        break;
    case(Qt::Key_Comma):
        button_press(".", 0);
        break;
    //

    }
 }

#define NUMS "1234567890"
bool is_num(QString text) {
    for (int i = 0; i < 10; i++) {
        if (NUMS[i] == text)
            return true;
    }
    return false;
}

double MainWindow::calculate(double a, double b, int type) {
    /*
        1 - сложить
        2 - вычесть
        3 - умножить
        4 - разделить
    */
    switch(operation) {
    case(1):
        return a + b;
        break;
    case(2):
        return a - b;
        break;
    case(3):
        return a * b;
        break;
    case(4):
        return a / b;
        break;
    default:
        break;
    }
}

void MainWindow::button_press(QString text, int type) {
//    qInfo() << text;
    double out;
    if (type == 7) { // вычисление
        if (buf && ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "") {
            out = calculate(buf, ui->lineEdit->text().toDouble(), type);
            ui->lineEdit->setText(QString::number(out));
            operation = 0;
            ui->lineEdit_2->setText("");
            buf = out;
        }
    }else if (type == 5) {
        ui->lineEdit->setText(
            QString::number(qSqrt(ui->lineEdit->text().toDouble()))
        );
    } else if (1 <= type && type <= 4) { // математические оперции
        operation = type;
        buf = ui->lineEdit->text().toDouble();
        ui->lineEdit_2->setText(text);
        clear_next = true;

    } else if (type == 6) { // удаление
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        clear_next = false;
        buf = NULL;
    } else if (type == 0) { // добавление цифр
        if (clear_next) {
            ui->lineEdit->setText("");
            clear_next = false;
        }
        ui->lineEdit->text();
        ui->lineEdit->setText(ui->lineEdit->text() + text);
    }
}
