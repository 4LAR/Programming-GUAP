#include "calculationfacade.h"

apartmentFactory* calculationFacade::apartment_factory =  new apartmentFactory;
luxuriousFactory* calculationFacade::luxurious_factory =  new luxuriousFactory;
cottageFactory* calculationFacade::cottage_factory =  new cottageFactory;
townhouseFactory* calculationFacade::townhouse_factory =  new townhouseFactory;

calculationFacade::calculationFacade(QObject *parent)
    : QObject{parent}
{

}

calculationFacade::~calculationFacade(){

}

double calculationFacade::getCost(estate *value){
    abstractCalc* house;
    switch(value->getType()){
    case estate::EstateType::ECONOM:{
        house = apartment_factory->createCalc();
        break;
    }
    case estate::EstateType::LUXURIOUS:{
        house = luxurious_factory->createCalc();
        break;
    }
    case estate::EstateType::TOWN_HOUSE:{
        house = townhouse_factory->createCalc();
        break;
    }
    case estate::EstateType::COTTAGE:{
        house = cottage_factory->createCalc();
        break;
    }
    default:{
        assert(false);
        break;
    }
 }
    return house->getCost(value);
}

// обстрактный дом + нужный тип данных для вычислений, для подключения нужной фабрики
