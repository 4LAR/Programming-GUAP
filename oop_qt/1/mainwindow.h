#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void button_press(QString, int);
    double calculate(double, double, int);

private:
    Ui::MainWindow *ui;

    double buf = NULL;
    int operation = 0;
    bool clear_next = false;

protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
