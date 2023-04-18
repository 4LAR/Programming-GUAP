#ifndef ESTATE_H
#define ESTATE_H

#include <QObject>

class Estate : public QObject
{
    Q_OBJECT
public:
    enum EstateType {
        ECONOM,
        LUXURIOUS,
        TOWN_HOUSE,
        COTTAGE
    };
    explicit Estate(int inputAge, int inputArea,int inputResidents, int inputMonths, EstateType inputEstateType,QString inputOwner,QObject *parent = nullptr);
    EstateType getType();
    int getMonths();
    int getArea();
    int getResidents();
    QString getName();
    int getAge();
private:
    int age;
    int area;
    int residents;
    int months;
    EstateType type;
    QString owner;
};

#endif // ESTATE_H
