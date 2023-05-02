#include "apartmentcalc.h"

double apartmentCalc::getCost(estate *value){
    return (value->getAge() + value->getArea() + value->getMonths() + value->getResidents()) * 1000;
}
