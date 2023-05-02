#include "townhousecalc.h"

double townhouseCalc::getCost(estate *value){
   return (value->getAge() + value->getArea() + value->getMonths() + value->getResidents()) * 2500;
}
