#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include "BankAccount.h"
#include "menuFunctions.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Transaction.h"


int main() {
    srand(time(NULL));
    BankAccount* currentUser = nullptr;
    int choice = 0; 
    bool isLogged = false;
    bool interestApplied = false;
    
    std::vector<BankAccount*> TheBank;
    
    do {
        printMenuChoices(currentUser, isLogged);
        choice = getMenuChoice(choice);
        
        
        switch(choice) {
            case 1:
                createAccount(TheBank, isLogged);
                break;
            case 2:
                selectAccount(TheBank, currentUser, isLogged);
                break;
            case 3:
                logout(currentUser, isLogged);
                break;
            case 4:
                makeDeposit(currentUser, isLogged);
                break;
            case 5:
                makeWithdrawal(currentUser, isLogged);
                break;
            case 6:
                printCurrentUser(currentUser, isLogged);
                break;  
            case 7:
                printAllUsers(TheBank);
                break;
            case 8:
                printTransactionHistory(currentUser, isLogged);
                break;
            case -1:
                break;
        }
    } while (choice != -1);
    
    // delete the accounts on exit.
    for (BankAccount* account : TheBank) {
        delete account;
    } 
    TheBank.clear();
    // std::cout << TheBank.empty() << std::endl;
    
    
    return 0;  
}
