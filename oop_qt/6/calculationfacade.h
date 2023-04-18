#ifndef CALCULATIONFACADE_H
#define CALCULATIONFACADE_H

#include <QObject>
#include <estate.h>
#include <apartmentcalc.h>
#include <luxuriousapartmentcalc.h>
#include <townhousecalc.h>
#include <cottagecalc.h>


class CalculationFacade : public QObject
{
    Q_OBJECT
public:
    explicit CalculationFacade(QObject *parent = nullptr);

    static int getCost(Estate *value);

signals:

};

#endif // CALCULATIONFACADE_H
