#include "apartmentfactory.h"

abstractCalc* apartmentFactory::createCalc(){
    return new apartmentCalc;
}
