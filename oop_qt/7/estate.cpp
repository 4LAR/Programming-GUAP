#include "estate.h"
#include <widget.h>

estate::estate(QObject *parent)
    : QObject{parent}
{

}

estate::estate(const QString owner, const int age, const int type,
               const int residents, const double area, const QString months){
    if (owner == "" || age == 0 || residents == 0 || area == 0)
        throw myException("Заполните все поля формы.");
    this->age = age;
    this->area = area;
    this->residents = residents;
    this->months = months.split(" ")[0].toInt();
    this->owner = owner;
    this->type = static_cast<EstateType>(type);
}

estate::EstateType estate::getType() const{
    return this->type;
}

int estate::getAge() const{
    return this->age;
}

double estate::getArea() const{
    return this->area;
}

int estate::getMonths() const{
    return this->months;
}

int estate::getResidents() const{
    return this->residents;
}

QString estate::getOwner() const{
    return this->owner;
}
