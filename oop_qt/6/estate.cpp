#include "estate.h"

Estate::Estate(int inputAge, int inputArea,int inputResidents, int inputMonths, EstateType inputEstateType,QString inputOwner,QObject *parent)
    : QObject{parent}
{
    age=inputAge;
    area=inputArea;
    residents=inputResidents;
    months=inputMonths;
    type=inputEstateType;
    owner=inputOwner;
}

Estate::getArea(){
    return area;
}

Estate::getMonths(){
    return months;
}

Estate::getResidents(){
    return residents;
}

Estate::EstateType Estate::getType(){
    return type;
}

QString Estate::getName(){
    return owner;
}

int Estate::getAge(){
    return age;
}
