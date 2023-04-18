#include "cottagecalc.h"
#include <QtMath>

cottagecalc::cottagecalc(QObject *parent)
    : QObject{parent}
{

}

cottagecalc::getCost(Estate *value){
    return (value->getMonths()+1)*value->getArea()*sqrt(value->getResidents())*500;
}
