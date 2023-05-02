#ifndef ABSTRACTCALC_H
#define ABSTRACTCALC_H

#include <estate.h>
//рефакторинг с помощью двух классов
class abstractCalc
{
public:
    abstractCalc();
    virtual double getCost(estate* value) = 0;
    virtual ~abstractCalc() {}
};

#endif // ABSTRACTCALC_H

//стоим
// для каждого объекта свой класс дом коттедж и тд + свой метод геткост
