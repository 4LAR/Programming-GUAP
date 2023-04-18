#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <states.h>
#include <estate.h>
#include <calculationfacade.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void update();
private slots:
    void btnCalcPressed();
    void btnUndoPressed();
    void on_btnCalc_clicked();

private:
    Ui::Widget *ui;
    Estate *processForm();
    void fillForm(Estate *value);
    void showCost(Estate *value);
    States info;

};
#endif // WIDGET_H
