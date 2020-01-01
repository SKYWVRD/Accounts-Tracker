#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <QString>
#include <accountlist.h>

class SavingsAccount: public Account
{
public:
    SavingsAccount(QString cn, QString an, double ir);
    void transaction(double amt);
    void calcInterest();
    int getPoints() const;
    QString toString() const;

private:
    double minIntEarnedForPoints;
    int points;
};

#endif // SAVINGSACCOUNT_H
