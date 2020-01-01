#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
#include <QList>
#include "transaction.h"

class Account
{
public:
    Account(QString cn, QString an, double ir, QString ty);
    QString getCustName() const;
    QString getAccNum() const;
    QList<Transaction> getTransaction() const;
    QString toString() const;
    QString getType() const;
    double getInterestRate() const;
    virtual void transaction(double amt) = 0;
    virtual void calcInterest() = 0;
    double getBalance() const;


protected:
    double balance;
    QList<Transaction> transactions;


private:
    QString custName;
    QString accNum;
    double interestRate;
    QString type;


};

class AccountList: public QList<Account*>{
public:
    ~AccountList();
    bool addAccount(Account* a);
    double totalBalance() const;
    void doInterestCalculations();
    QString toString() const;
    QStringList customersWithHighestPoints() const;
private:
    Account* findAccount(QString an);

};

#endif // ACCOUNT_H
