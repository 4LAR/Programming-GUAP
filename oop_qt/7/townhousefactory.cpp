#include "townhousefactory.h"

abstractCalc* townhouseFactory::createCalc(){
    return new townhouseCalc;
}
