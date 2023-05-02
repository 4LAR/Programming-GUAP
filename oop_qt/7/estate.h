#ifndef ESTATE_H
#define ESTATE_H

#include <QObject>

class estate : public QObject
{
    Q_OBJECT
public:
    explicit estate(QObject *parent = nullptr);
    enum EstateType{
        ECONOM,
        LUXURIOUS,
        TOWN_HOUSE,
        COTTAGE
    };
    estate(const QString owner, const int age, const int type,
           const int residents, const double area, const QString months);
    EstateType getType() const;
    int getAge() const;
    int getMonths() const;
    double getArea() const;
    int getResidents() const;
    QString getOwner() const;

private:
    int age, residents, months;
    double area;
    EstateType type;
    QString owner;
};

#endif // ESTATE_H
