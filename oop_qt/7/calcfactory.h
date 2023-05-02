#ifndef CALCFACTORY_H
#define CALCFACTORY_H

#include <apartmentcalc.h>
#include <cottagecalc.h>
#include <luxuriouscalc.h>
#include <townhousecalc.h>

class calcFactory
{
public:
    calcFactory();
    virtual abstractCalc* createCalc() = 0;
    virtual ~calcFactory() {}

};

#endif // CALCFACTORY_H

//рефакторинг с помощью двух классов

//создание объектов нужных для вычисления + своя именная факторка

