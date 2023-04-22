#include <iostream>
#include <iomanip>
#include "Investment.h"

using namespace std;

//default constructor initializing values to 0
Investment::Investment() {
    initialAmt = 0.0;
    monthlyDeposit = 0.0;
    interest = 0.0;
    years = 0;
}

//function to print the initial menu asking for user input values
void Investment::printMenu() {
    cout << "**********************************" << endl;;
    cout << "*********** Data Input ***********" << endl;
    cout << "Initial Investment Amount: $";
    cin >> initialAmt;
    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    cout << "Annual Interest (%): ";
    cin >> interest;
    cout << "Number of years: ";
    cin >> years;
    cout << "Press any key to continue..." << endl;
    cin.ignore();
    getchar();
}

//function to print out the balance report if no additional monthly deposits were made
void Investment::balanceWithoutDeposits() {
    double yearEndBalance;
    double earnedInterest;

    cout << "\tBalance and Interest Without Additional Monthly Deposits" << endl;
    cout << "========================================================================" << endl;
    cout << "Year \t\t Year End Balance\t\tYear End Earned Interest" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    yearEndBalance = initialAmt;
    for (int i = 1; i <= years; i++) {
        earnedInterest = yearEndBalance * (interest / 100);
        yearEndBalance += earnedInterest;
        cout << i << "\t\t\t$" << fixed << setprecision(2) << yearEndBalance << "\t\t\t\t" << fixed << setprecision(2) << earnedInterest << endl << endl;
    }
}

//function to print out the balance report if additional monthly deposits were made
void Investment::balanceWithDeposits() {
    double yearEndBalance;
    double earnedInterest = 0;
    double monthEndBalance;
    double monthEarnedInterest;

    cout << "\t Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "========================================================================" << endl;
    cout << "Year \t\t Year End Balance\t\tYear End Earned Interest" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    monthEndBalance = initialAmt;
    yearEndBalance = initialAmt + (monthlyDeposit * 12);
    for (int i = 1; i <= years; i++) { //calculating year end balance and earned interest
        for (int j = 0; j < 12; j++) { //nested loop calculating the earned interest and final balance for each month during the year
            monthEarnedInterest = (monthEndBalance + monthlyDeposit) * ((interest / 100) / 12);
            monthEndBalance += monthlyDeposit + monthEarnedInterest;
            earnedInterest += monthEarnedInterest;
        }
        yearEndBalance = monthEndBalance;
        cout << i << "\t\t\t$" << fixed << setprecision(2) << yearEndBalance << "\t\t\t\t" << fixed << setprecision(2) << earnedInterest << endl;
        earnedInterest = 0; //re-initializing this to 0 so that the interest doesn't become a cumulative number
        }
}