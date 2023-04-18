#include "states.h"

States::States(QObject *parent)
    : QObject{parent}
{
    actualData = nullptr;
}

States::~States()
{
    //delete: actualData
    if(actualData){
        delete actualData;
        actualData=nullptr;
    }
    //delete and clear array
    array.clear();
    qDeleteAll(array);

}

bool States::hasStates(){
    return !array.empty();
}

    Estate *States::getActualData(){
        //return array.takeLast();
        return array.back();
        //return array.takeAt(array.size()-1);
    }

void States::add(Estate *value){
    array.append(value);
}

void States::undo(){
    if(!hasStates()||(array.size()==1)){
        actualData=nullptr;
    }
    else {
        actualData=getActualData();
        array.removeLast();
        emit notifyObservers();
    }
}
