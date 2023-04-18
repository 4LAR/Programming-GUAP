#include "luxuriousapartmentcalc.h"
#include <QtMath>

luxuriousapartmentcalc::luxuriousapartmentcalc(QObject *parent)
    : QObject{parent}
{

}

luxuriousapartmentcalc::getCost(Estate *value){
    return (value->getMonths()+1)*value->getArea()*sqrt(value->getResidents())*175;
}
