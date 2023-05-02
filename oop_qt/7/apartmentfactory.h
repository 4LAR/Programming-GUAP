#ifndef APARTMENTFACTORY_H
#define APARTMENTFACTORY_H

#include <calcfactory.h>

class apartmentFactory : public calcFactory
{
public:
    abstractCalc* createCalc();
    ~apartmentFactory() {}
};

#endif // APARTMENTFACTORY_H
