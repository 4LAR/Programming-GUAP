#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QDir>
#include <QList>
#include "variant.h"
#include "work.h"
#include <QListWidget>
#include <QtMath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void PrintOld();
    void PrintNew();
    ~MainWindow();

signals:
    void workSignal(QString string);
    void variantSignal(QString spisok);

private:
    Ui::MainWindow *ui;
    Variant *variant{};

private slots:
    void readFile();
    void clear_collection();
    void summ_el();
    void summ_chet();
    void add_el();
    void SearchToIndex();
    void DeleteToIndex();
    void DeleteToCount();
    void writeFile();
    void zadanie_1();
    void zadanie_2();
};

#endif // MAINWINDOW_H
