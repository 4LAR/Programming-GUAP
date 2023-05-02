#include "cottagecalc.h"

double cottageCalc::getCost(estate *value){
    return (value->getAge() + value->getArea() + value->getMonths() + value->getResidents()) * 3000;
}
