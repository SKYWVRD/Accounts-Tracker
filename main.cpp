#include <QCoreApplication>
#include <QTextStream>
#include "accountlist.h"
#include "chequeaccount.h"
#include "savingsaccount.h"
#include "transaction.h"

#include <iostream>
#include <QTextStream>

QTextStream conOut(stdout);
QTextStream conIn(stdin);



void addSavings(AccountList &accL);
void addCheque(AccountList &accL);
void transactionsOutput(QString accNum, AccountList& accL);

int main()
{
    AccountList newBank;
    //Add 3 Savings Accounts
    addSavings(newBank);
    addSavings(newBank);
    addSavings(newBank);
    //Add 3 Cheque Accounts
    addCheque(newBank);
    addCheque(newBank);
    addCheque(newBank);

    conOut << "======== Savings Test 1 ========" << endl;
    //Transactions on first Savings
    newBank.at(0)->transaction(500);
    newBank.at(0)->transaction(-50);
    newBank.at(0)->transaction(250);
    conOut << "======== Savings Test 2 ========" << endl;
    //Transactions on Second Savings
    newBank.at(1)->transaction(-100);
    newBank.at(1)->transaction(600);
    newBank.at(1)->transaction(-250);
    conOut << "======== Savings Test 3 ========" << endl;
    //Transactions on Third Savings
    newBank.at(2)->transaction(-500);
    newBank.at(2)->transaction(-50);
    newBank.at(2)->transaction(-250);
    conOut << "======== Cheque Test 1 ========" << endl;
    //Transactions on First Cheque
    newBank.at(3)->transaction(500);
    newBank.at(3)->transaction(-50);
    newBank.at(3)->transaction(250);
    conOut << "======== Cheque Test 2 ========" << endl;
    //Transactions on Second Cheque
    newBank.at(4)->transaction(-100);
    newBank.at(4)->transaction(600);
    newBank.at(4)->transaction(-250);
    conOut << "======== Cheque Test 3 ========" << endl;
    //Transactions on Third Cheque
    newBank.at(5)->transaction(-500);
    newBank.at(5)->transaction(-50);
    newBank.at(5)->transaction(-250);

    conOut << "======== Savings 1 Transaction History Before Interest ========" << endl;
    transactionsOutput("1", newBank);
    conOut << "======== Savings 2 Transaction History Before Interest ========" << endl;
    transactionsOutput("2", newBank);
    conOut << "======== Savings 3 Transaction History Before Interest ========" << endl;
    transactionsOutput("3", newBank);
    conOut << "======== Cheque 1 Transaction History Before Interest ========" << endl;
    transactionsOutput("4", newBank);
    conOut << "======== Cheque 2 Transaction History Before Interest ========" << endl;
    transactionsOutput("5", newBank);
    conOut << "======== Cheque 3 Transaction History Before Interest ========" << endl;
    transactionsOutput("6", newBank);

    newBank.doInterestCalculations();

    conOut << "======== Savings 1 Transaction History After Interest ========" << endl;
    transactionsOutput("1", newBank);
    conOut << "======== Savings 2 Transaction History After Interest ========" << endl;
    transactionsOutput("2", newBank);
    conOut << "======== Savings 3 Transaction History After Interest ========" << endl;
    transactionsOutput("3", newBank);
    conOut << "======== Cheque 1 Transaction History After Interest ========" << endl;
    transactionsOutput("4", newBank);
    conOut << "======== Cheque 2 Transaction History After Interest ========" << endl;
    transactionsOutput("5", newBank);
    conOut << "======== Cheque 3 Transaction History After Interest ========" << endl;
    transactionsOutput("6", newBank);

    conOut << "QString of All Accounts" << endl;
    conOut << newBank.toString() << endl;

}


void addSavings(AccountList& accL)
{
    Account* acc;

    conOut << "Please enter an account number: ";
    conOut.flush();
    QString accNum = "";
    conIn >> accNum;
    acc = new SavingsAccount("Sean", accNum, 5.0);\

    accL.addAccount(acc);

    return;

}

void addCheque(AccountList& accL)
{
    Account* acc;

    conOut << "Please enter an account number: ";
    conOut.flush();
    QString accNum = "";
    conIn >> accNum;
    acc = new ChequeAccount("Sean", accNum, 10.0, 100);

    accL.addAccount(acc);


    return;

}


void transactionsOutput(QString accNum, AccountList& accL)
{
    bool accountFound = false;
    int counter = 0;

    do
    {
        if(accL.at(counter)->getAccNum() == accNum)
            accountFound = true;
        else
            counter++;

    }while(accountFound == false);

    if(accountFound == true)
    {
        QList<Transaction> newList = accL.at(counter)->getTransaction();
        for(int i = 0; i < newList.size(); i++)
        {
            conOut << newList.at(i).getType() << " " << newList.at(i).getAmount() << endl;
        }
    }
    else
        conOut << "Account does not exist" << endl;

    return;

}
