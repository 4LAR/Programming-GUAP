#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QString>
#include <QStringListModel>

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
    void append_to_history(QString);
    void clear_to_history();

private:
    Ui::MainWindow *ui;

    double buf = NULL;
    int operation = 0;
    bool clear_next = false;

    QStringListModel *model = new QStringListModel(this);
    QStringList List;

protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
