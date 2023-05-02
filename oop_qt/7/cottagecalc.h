#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include <abstractcalc.h>

class cottageCalc : public abstractCalc
{
public:
    virtual double getCost(estate* value);

};

#endif // COTTAGECALC_H
