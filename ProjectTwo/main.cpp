#include <iostream>
#include "Investment.h"

using namespace std;

int main() {
    
    string userInput = "";

    while (userInput != "QUIT") { 
    Investment investment;
    investment.printMenu();
    investment.balanceWithoutDeposits();
    investment.balanceWithDeposits();

    cout << "Would you like to enter new values? Type anything to continue, or type 'QUIT' to end the program" << endl;;
    cin >> userInput;
    }
    cout << "Goodbye" << endl;

    return 0;
}