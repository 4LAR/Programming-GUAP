#include "townhousecalc.h"
#include <QtMath>

townhousecalc::townhousecalc(QObject *parent)
    : QObject{parent}
{

}

townhousecalc::getCost(Estate *value){
    return (value->getMonths()+1)*value->getArea()*sqrt(value->getResidents())*275;
}
