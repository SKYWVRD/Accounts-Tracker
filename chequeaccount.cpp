#include "chequeaccount.h"
#include <QTextStream>

QTextStream chequeOut(stdout);

ChequeAccount::ChequeAccount(QString cn, QString an, double ir, double od): Account(cn, an, ir, "Cheque")
{
    this->overdraft = od*(-1);
}

void ChequeAccount::transaction(double amt)
{
    if(amt>0)
    {
        transactions.append(Transaction("Deposit", amt));
        this->balance = this->balance + amt;
        chequeOut << "Deposited " << amt << " New Balance is: R" << this->balance << endl;
    }
    else if(amt<0)
    {
        double odCheck = this->balance + amt;
        if(odCheck < this->overdraft)
        {
            transactions.append(Transaction("Failed Withdrawal, Overdraft reached", amt));
            chequeOut << "Overdraft Reached, please settle account" << endl;
        }
        else
        {
            transactions.append(Transaction("Withdrawal", amt));
            this->balance = this->balance + amt;
            chequeOut << "Withdrew " << amt << " New Balance is: R" << this->balance << endl;
        }

    }


}

void ChequeAccount::calcInterest()
{
    double currentBalance = this->balance;
    double interest = currentBalance * ((this->getInterestRate()/100));

    if(this->balance < 0)
    {
        this->balance = currentBalance - interest;
        transactions.append(Transaction("Negative Interest", interest));
    }
    else
    {
        this->balance = currentBalance + interest;
        transactions.append(Transaction("Positive Interest", interest));
    }

}

double ChequeAccount::getOverdraft() const
{
    return overdraft;
}
QString ChequeAccount::toString() const
{
    return QString("%1, %2, %3, %4, %5").arg(this->getCustName()).arg(this->getAccNum()).arg(this->getInterestRate()).arg(this->getType()).arg(this->getBalance());
}
