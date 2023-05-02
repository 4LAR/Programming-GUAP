#ifndef STATES_H
#define STATES_H

#include <QObject>
#include <estate.h>

class states : public QObject
{
    Q_OBJECT
public:
    explicit states(QObject *parent = nullptr);
    ~states();

    void undo();
    bool hasStates();
    estate *getActualData();
    void add(estate *value);
    int getSize();

signals:
    void notifyObservers();
private:
    QList<estate*> array;
    estate *actualData;
};

#endif // STATES_H
