#ifndef VARIANT_H
#define VARIANT_H

#include <QObject>
#include <QtMath>
#include <QList>
#include <QDebug>
class Variant : public QObject
{
    Q_OBJECT
public:
    explicit Variant(QObject *parent = 0);

signals:

public slots:
    void variantSlot();
};

#endif // VARIANT_H
