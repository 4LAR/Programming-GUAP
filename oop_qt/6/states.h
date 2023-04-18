#ifndef STATES_H
#define STATES_H

#include <QObject>
#include <estate.h>

class States : public QObject
{
    Q_OBJECT
public:
    explicit States(QObject *parent = nullptr);
    ~States();
    void undo();
    bool hasStates();
    Estate *getActualData();
    void add(Estate *value);
private:
    QList<Estate *> array;
    Estate *actualData;
signals:
    void notifyObservers();
};

#endif // STATES_H
