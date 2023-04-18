#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include <QObject>
#include <estate.h>

class cottagecalc : public QObject
{
    Q_OBJECT
public:
    explicit cottagecalc(QObject *parent = nullptr);

    int getCost(Estate *value);

signals:

};

#endif // COTTAGECALC_H
