#ifndef WORK_H
#define WORK_H

#include <QObject>

class Work : public QObject
{
    Q_OBJECT
public:
    explicit Work(QObject *parent = 0);

signals:

public slots:

    void WorkSlot1(QString string);
};

#endif // WORK_H
