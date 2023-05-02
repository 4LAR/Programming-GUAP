#include "cottagefactory.h"

abstractCalc* cottageFactory::createCalc(){
    return new cottageCalc;
}
