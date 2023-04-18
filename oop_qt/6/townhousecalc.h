#ifndef TOWNHOUSECALC_H
#define TOWNHOUSECALC_H

#include <QObject>
#include <estate.h>

class townhousecalc : public QObject
{
    Q_OBJECT
public:
    explicit townhousecalc(QObject *parent = nullptr);

    int getCost(Estate *value);
signals:

};

#endif // TOWNHOUSECALC_H
