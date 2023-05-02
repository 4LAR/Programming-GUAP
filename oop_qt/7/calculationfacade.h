#ifndef CALCULATIONFACADE_H
#define CALCULATIONFACADE_H

#include <cassert>
#include <QObject>
#include <apartmentfactory.h>
#include <luxuriousfactory.h>
#include <cottagefactory.h>
#include <townhousefactory.h>

class calculationFacade : public QObject
{
    Q_OBJECT
public:
    explicit calculationFacade(QObject *parent = nullptr);
    static double getCost(estate *value);
    ~calculationFacade();
private:
    static apartmentFactory* apartment_factory;
    static luxuriousFactory* luxurious_factory;
    static cottageFactory* cottage_factory;
    static townhouseFactory* townhouse_factory;
};

#endif // CALCULATIONFACADE_H


// ститические объекты для избежания утечек памяти
