#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QString>

class Transaction
{
public:
    Transaction(QString ty, double amt);
    QString getType() const;
    double getAmount() const;
    QString toString() const;

private:
    QString type;
    double amount;
};

#endif // TRANSACTION_H
