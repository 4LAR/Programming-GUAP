#ifndef TOWNHOUSECALC_H
#define TOWNHOUSECALC_H

#include <abstractcalc.h>

class townhouseCalc : public abstractCalc
{
public:
    virtual double getCost(estate* value);

};

#endif // TOWNHOUSECALC_H
