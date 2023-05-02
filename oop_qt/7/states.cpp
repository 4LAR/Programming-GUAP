#include "states.h"

states::states(QObject *parent)
    : QObject{parent}
{
    actualData = nullptr;
}

states::~states(){
    if (actualData){
        delete actualData;
        actualData = nullptr;
    }

    qDeleteAll(array);
    array.clear();
}

bool states::hasStates(){
    return !(array.isEmpty());
}

estate* states::getActualData(){
    return actualData;
}

void states::add(estate* value){
    array.append(value);
}

void states::undo(){
    if (hasStates()){
        array.pop_back();
        actualData = array.last();
        emit notifyObservers();
    }
    else actualData = nullptr;
}

int states::getSize(){
    return array.size();
}
