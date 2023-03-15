#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_radioButton_col_clicked(bool checked);

    void on_radioButton_bras_clicked(bool checked);

    void on_radioButton_cep_clicked(bool checked);

    void on_radioButton_iron_clicked(bool checked);

    void on_radioButton_copper_clicked(bool checked);

    void on_radioButton_gold_clicked(bool checked);

    void on_pushButton_end_clicked();

    void calculatePrice();

    void on_groupBox_2_clicked();

    void on_lineEdit_size_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
