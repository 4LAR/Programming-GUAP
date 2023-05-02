#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <states.h>
#include <estate.h>
#include <calculationfacade.h>
#include <exception.h>
#include <QRegularExpressionValidator>
#include <QRegularExpression>

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
    void calcPressed();
    void undoPressed();

private:
    estate *processForm();
    void fillForm(estate *value);
    void showCost(estate *value);

private:
    Ui::Widget *ui;
    QRegularExpressionValidator forIntValidator, forDoubleValidator,
                                forOwnerValidator;
    states info;
};
#endif // WIDGET_H
