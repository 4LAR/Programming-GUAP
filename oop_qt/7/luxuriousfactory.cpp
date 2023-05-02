#include "luxuriousfactory.h"

abstractCalc* luxuriousFactory::createCalc(){
    return new luxuriousCalc;
}
