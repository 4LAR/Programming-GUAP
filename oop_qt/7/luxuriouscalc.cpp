#include "luxuriouscalc.h"

double luxuriousCalc::getCost(estate *value){
   return (value->getAge() + value->getArea() + value->getMonths() + value->getResidents()) * 1500;
}
