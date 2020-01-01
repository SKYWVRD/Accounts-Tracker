#ifndef CHEQUEACCOUNT_H
#define CHEQUEACCOUNT_H
#include <QString>
#include <accountlist.h>

class ChequeAccount: public Account
{
public:
    ChequeAccount(QString cn, QString an, double ir, double od);
    void transaction(double amt);
    void calcInterest();
    double getOverdraft() const;
    QString toString() const;

private:
    double overdraft;

};

#endif // CHEQUEACCOUNT_H
