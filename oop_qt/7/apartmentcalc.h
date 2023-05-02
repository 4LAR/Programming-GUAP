#ifndef APARTMENTCALC_H
#define APARTMENTCALC_H

#include <abstractcalc.h>

class apartmentCalc : public abstractCalc
{
public:
    virtual double getCost(estate* value);
};

#endif // APARTMENTCALC_H
