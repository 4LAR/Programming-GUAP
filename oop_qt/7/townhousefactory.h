#ifndef TOWNHOUSEFACTORY_H
#define TOWNHOUSEFACTORY_H

#include <calcfactory.h>

class townhouseFactory : public calcFactory
{
public:
    abstractCalc* createCalc();
    ~townhouseFactory() {}
};

#endif // TOWNHOUSEFACTORY_H
