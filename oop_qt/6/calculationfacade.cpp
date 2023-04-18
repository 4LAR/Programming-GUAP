#include "calculationfacade.h"

CalculationFacade::CalculationFacade(QObject *parent)
    : QObject{parent}
{

}

int CalculationFacade::getCost(Estate *value) {

    int cost;

    if (value->getType() == Estate::EstateType::ECONOM) {
        apartmentcalc a;
        cost = a.getCost(value);
    } else if (value->getType() == Estate::EstateType::LUXURIOUS) {
        luxuriousapartmentcalc l;
        cost = l.getCost(value);
    } else if (value->getType() == Estate::EstateType::TOWN_HOUSE) {
        townhousecalc t;
        cost = t.getCost(value);
    } else if (value->getType() == Estate::EstateType::COTTAGE) {
        cottagecalc c;
        cost =c.getCost(value);
    } else {
        cost = -1;
    }
    return cost;
}
