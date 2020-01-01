#include "transaction.h"

Transaction::Transaction(QString ty, double amt)
{
    this->type = ty;
    this->amount = abs(amt);

}

QString Transaction::getType() const
{
    return type;
}

double Transaction::getAmount() const
{
    return amount;
}

QString Transaction::toString() const
{
    return QString("%1, %2").arg(this->getType()).arg(this->getAmount());
}
