#include "variant.h"

Variant::Variant(QObject *parent) : QObject(parent)
{

}

void Variant::variantSlot()
{
    QString spisok;
    qDebug() << "Слот запущен" << spisok;


}
