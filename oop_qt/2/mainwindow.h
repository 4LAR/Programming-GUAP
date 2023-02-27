#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QStringList>
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

    void loadBoxes();
    void loadImages();
    void update_count(QString, int);
    int get_id(QString);
    void generate_price(bool);

private slots:
   void test(QListWidgetItem *item);

   void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QStringListModel *model = new QStringListModel(this);
    int id_main = -1;

};
#endif // MAINWINDOW_H
