#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment {
public:
    Investment();
    void printMenu();
    void balanceWithoutDeposits();
    void balanceWithDeposits();
private:
    double initialAmt;
    double monthlyDeposit;
    double interest;
    int years;
    void reportHeader();
};

#endif