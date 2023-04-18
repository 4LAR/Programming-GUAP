#ifndef LUXURIOUSAPARTMENTCALC_H
#define LUXURIOUSAPARTMENTCALC_H

#include <QObject>
#include <estate.h>

class luxuriousapartmentcalc : public QObject
{
    Q_OBJECT
public:
    explicit luxuriousapartmentcalc(QObject *parent = nullptr);

    int getCost(Estate *value);
signals:

};

#endif // LUXURIOUSAPARTMENTCALC_H
