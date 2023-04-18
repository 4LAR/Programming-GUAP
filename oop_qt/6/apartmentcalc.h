#ifndef APARTMENTCALC_H
#define APARTMENTCALC_H

#include <QObject>
#include <estate.h>

class apartmentcalc : public QObject
{
    Q_OBJECT
public:
    explicit apartmentcalc(QObject *parent = nullptr);

    int getCost(Estate *value);
signals:

};

#endif // APARTMENTCALC_H
