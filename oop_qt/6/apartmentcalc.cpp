#include "apartmentcalc.h"
#include <QtMath>

apartmentcalc::apartmentcalc(QObject *parent)
    : QObject{parent}
{

}

apartmentcalc::getCost(Estate *value){
    return (value->getMonths()+1)*value->getArea()*sqrt(value->getResidents())*150;
}
