#ifndef COTTAGEFACTORY_H
#define COTTAGEFACTORY_H

#include <calcfactory.h>

class cottageFactory : public calcFactory
{
public:
    abstractCalc* createCalc();
    ~cottageFactory() {}
};

#endif // COTTAGEFACTORY_H
