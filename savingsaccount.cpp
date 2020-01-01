#include "savingsaccount.h"
#include <QTextStream>

QTextStream savOut(stdout);

SavingsAccount::SavingsAccount(QString cn, QString an, double ir): Account(cn, an, ir, "Savings")
{
    this->points = 0;
}

void SavingsAccount::transaction(double amt)
{
    if(amt>0)
    {
        transactions.append(Transaction("Deposit", amt));
        this->balance = this->balance + amt;
        savOut << "Deposited " << amt << " New Balance is: R" << this->balance << endl;

    }
    else if(amt<0)
    {
        double balanceCheck = this->balance + amt;
        if(balanceCheck < 0)
        {
            transactions.append(Transaction("Insufficient Funds", amt));
            savOut << "You have insufficient funds" << endl;
        }
        else
        {
            transactions.append(Transaction("Withdrawal", amt));
            this->balance = this->balance + amt;
            savOut << "Withdrew " << amt << " New Balance is: R" << this->balance << endl;


        }

    }
}

void SavingsAccount::calcInterest()
{
    double currentBalance = this->balance;
    double interest = currentBalance * ((this->getInterestRate()/100));

    this->balance = currentBalance + interest;
    transactions.append(Transaction("Interest", interest));

    if(interest > this->minIntEarnedForPoints)
    {
       int pointsEarned = int(interest);
       this->points = this->points + pointsEarned;
    }
}

int SavingsAccount::getPoints() const
{
    return points;
}

QString SavingsAccount::toString() const
{
    return QString("%1, %2, %3, %4, %5").arg(this->getCustName()).arg(this->getAccNum()).arg(this->getInterestRate()).arg(this->getType()).arg(this->getBalance());
}

