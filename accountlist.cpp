#include "accountlist.h"
#include "QTextStream"

QTextStream cerr(stdout);

//start id=accimp
Account::Account(QString cn, QString an, double ir, QString ty)
{
    this->custName = cn;
    this->accNum = an;
    this->interestRate = ir;
    this->type = ty;
    this->balance = 0;
}

QString Account::getCustName() const
{
    return custName;
}
QString Account::getAccNum() const
{
    return accNum;
}
QList<Transaction> Account::getTransaction() const
{
    return transactions;
}
QString Account::toString() const
{
    return QString("%1, %2, %3, %4, %5").arg(this->custName).arg(this->accNum).arg(this->interestRate).arg(this->type).arg(this->balance);
}
QString Account::getType() const
{
    return type;
}
double Account::getInterestRate() const
{
    return interestRate;
}

double Account::getBalance() const
{
    return this->balance;
}

//start id=acclistimp

AccountList::~AccountList()
{
    qDeleteAll(*this);
    clear();
}

bool AccountList::addAccount(Account* a)
{
    if(findAccount(a->getAccNum()) == NULL)
    {
        append(a);
        return true;
    }
    else
    {
        cerr << "Account not added" << endl;
        return false;

    }
}

double AccountList::totalBalance() const
{
   double total = 0;

   for(int i = 0; i < size(); i++)
   {
       total = total + at(i)->getBalance();
   }

   return total;
}

void AccountList::doInterestCalculations()
{
    for(int i = 0; i < size(); i++)
    {
        at(i)->calcInterest();
    }
}

QString AccountList::toString() const
{
    QString allAccountsString;
    for(int i = 0; i < size(); i++)
    {
        allAccountsString.append(at(i)->toString());
        allAccountsString.append("\n");
    }

    return allAccountsString;
}

QStringList AccountList::customersWithHighestPoints() const
{
    int highestPoints = 0;
    QStringList custList;

    for(int i = 0; i < size(); i++)
    {

    }

    if(custList.size() == 0)
    {
        custList.append("None");
        return custList;
    }
    else
    {
        return custList;
    }
}

Account* AccountList::findAccount(QString an)
{
    bool accFound = false;
    for(int i = 0; i < size(); i++)
    {
       if(at(i)->getAccNum() == an)
       {
           accFound = true;
           return at(i);

       }
    }

    if(!accFound)
        return NULL;

}


