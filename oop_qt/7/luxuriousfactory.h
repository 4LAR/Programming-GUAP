#ifndef LUXURIOUSFACTORY_H
#define LUXURIOUSFACTORY_H

#include <calcfactory.h>

class luxuriousFactory : public calcFactory
{
public:
    abstractCalc* createCalc();
    ~luxuriousFactory() {}
};

#endif // LUXURIOUSFACTORY_H
