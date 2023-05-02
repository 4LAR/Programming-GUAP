#ifndef LUXURIOUSCALC_H
#define LUXURIOUSCALC_H

#include <abstractcalc.h>

class luxuriousCalc : public abstractCalc
{
public:
    virtual double getCost(estate* value);

};

#endif // LUXURIOUSCALC_H
