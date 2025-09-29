#include <iostream>
#include <string>
#include <vector>
#include "menuFunctions.h"

// testers
void testBankAccountClass() {
    BankAccount Melvino; // default
    // BankAccount Ning("Ning", 500); 
    // BankAccount Ning("Ning"); // exclude the second parameter (balance)
    
    Melvino.setAccountHolderName("Melvino Roxas");
    std::cout << "account name: " << Melvino.getAccountHolderName() << std::endl;
    std::cout << "account number: " << Melvino.getAccountNumber() << std::endl;
    
    Melvino.deposit(500.45);
    std::cout << "Total balance after deposit: " << Melvino.getBalance() << std::endl;
    
    Melvino.withdraw(500);
    std::cout << "Total balance after withdrawal: " << Melvino.getBalance() << std::endl;
}
void testBankAccountEqualAccNum() {
    BankAccount JohnDoe;
    BankAccount JaneDoe;
    
    if (JohnDoe == JaneDoe) { // compare account numbers
        std::cout << "Same account number" << std::endl; 
    } else {
        std::cout << "Not the same account number" << std::endl;
    }
}
void testBankAccountGreaterLessThan() {
    BankAccount JohnDoe("John");
    BankAccount JaneDoe("Jane");
    
    JohnDoe.deposit(400);
    JaneDoe.deposit(200);
    
    if (JohnDoe > JaneDoe) {
        std::cout << JohnDoe.getAccountHolderName() << " has more money than " << JaneDoe.getAccountHolderName() << std::endl;
    } 
    
    if (JohnDoe < JaneDoe) {
        std::cout << JohnDoe.getAccountHolderName() << " has less money than " << JaneDoe.getAccountHolderName() << std::endl;
    }
}
void testCheckingAndSavingsAccount() {
    
    CheckingAccount* checking;
    SavingsAccount* savings;
    
    std::cout << "CHECKING: " << std::endl;
    checking = new CheckingAccount;
    
    checking->deposit(500);
    std::cout << "balance after deposit: " << checking->getBalance() << std::endl;
    
    checking->withdraw(200);
    std::cout << "balance after withdrawal: " << checking->getBalance() << std::endl;

    std::cout << "SAVINGS:" << std::endl;
    savings = new SavingsAccount;
    
    delete checking;
    delete savings;
}
//

void createAccountInput(BankAccount *account) {
    std::string nameInp;
    double balanceInp;
    
    std::cout << "--Enter New User Name and Balance: " << std::endl;
    
    std::getline(std::cin, nameInp);
    
    std::cin >> balanceInp;
    
    // validate input
    if (std::cin.fail()) {
        std::cin.clear(); // clear the error flags  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "--Invalid input. Try again." << std::endl;
        return;
    }
    
    account->setAccountHolderName(nameInp);
    account->deposit(balanceInp);
    
    std::cout << "--Account Creation Successful." << std::endl;
}

void createAccount(std::vector<BankAccount*> &Bank, bool isLogged) {
    if (!isLogged) {
        int accountChoice;
        
    
        std::cout << "--Enter 1: Create a Savings Account" << std::endl;
        std::cout << "--Enter 2: Create a Checking Account" << std::endl;
        std::cout << "==> ";
        
        std::cin >> accountChoice; 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the left over new line
        std::cout << std::endl;
        
        // validate input
        if (std::cin.fail() || ((accountChoice < 1) || (accountChoice > 2))) {
            std::cin.clear(); // clear the error flags  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "--Invalid input. Not an Integer or Out of Range. Try again." << std::endl;
            return;
        }
        
        if (accountChoice == 1) {
            SavingsAccount* savings = new SavingsAccount(); 
            createAccountInput(savings); // allow the user to enter their username, balance, etc. 
            savings->calculateInterest(); // just add interest once for now. 
            Bank.push_back(savings);
        } else if (accountChoice == 2) {
            CheckingAccount* checking = new CheckingAccount();
            createAccountInput(checking); 
            Bank.push_back(checking);
        }
    } else {
        std::cout << "--You are already logged in! Logout to create a new account." << std::endl;
    }
}


void selectAccount(std::vector<BankAccount*> &Bank, BankAccount *&currentUser, bool &isLogged) { 
    if (isLogged) {
        std::cout << "--Already logged in. Log out if you wish to switch accounts." << std::endl;
        return;
    }
    
    std::cout << "Enter User Name: " << std::endl;
    std::string userLoginInp;
    std::getline(std::cin, userLoginInp);
    
    for (int i = 0; i < Bank.size(); i++) {
        if ((Bank.at(i)->getAccountHolderName() == userLoginInp) && !isLogged) {
            currentUser = Bank.at(i); // still points to actual account;
            isLogged = true;
            std::cout << "--Successful. Welcome, " << currentUser->getAccountHolderName() << "." << std::endl;
            return; 
        }
    }
    
    std::cout << "--User Does Not Exist" << std::endl;
}

void logout(BankAccount *&currentUser, bool &isLogged) {
    if ((currentUser != nullptr) && (isLogged == true)) {
        currentUser = nullptr; // logout
        isLogged = false;
        std::cout << "--Successfully Logged Out" << std::endl;
    } else {
        std::cout << "--You are not logged in!" << std::endl;
    }
}

void makeDeposit(BankAccount *&currentUser, bool isLogged) {
    if (isLogged) {
        double depositInp;
        std::cout << "--Amount: " << std::endl;
        std::cin >> depositInp;
        
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flags  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "--Invalid input. Not a number. Try again." << std::endl;
            return;
        }
        
        // currentUser->deposit(depositInp); 
        *currentUser += depositInp;
        std::cout << "--Deposit of $" << depositInp << " successful." << std::endl;
    } else {
        std::cout << "--You are not logged in!" << std::endl;
    }
}

void makeWithdrawal(BankAccount *&currentUser, bool isLogged) {
    if (!isLogged) {
        std::cout << "--You are not logged in!" << std::endl;
        return;
    }
    
    double withdrawInp;
    
    std::cout << "--Amount: " << std::endl;
    std::cin >> withdrawInp ;
    
    if (std::cin.fail()) {
            std::cin.clear(); // clear the error flags  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "--Invalid input. Not a number. Try again." << std::endl;
            return;
    }
    
    // currentUser->withdraw(withdrawInp);
    *currentUser -= withdrawInp;
}

void printUserBalance(const BankAccount *currentUser, bool isLogged) {
    if (!isLogged) {
        std::cout << "--You are not logged in!" << std::endl;
        return;
    }
    
    std::cout << "Balance: $" << currentUser->getBalance() << std::endl;
}

void printCurrentUser(const BankAccount *currentUser, bool isLogged) {
    if (!isLogged) {
        std::cout << "--You are not logged in!" << std::endl;
        return;
    }
    
    BankAccount::printAccount(currentUser);
}

void printAllUsers(const std::vector<BankAccount*> Bank) { 
    if (Bank.size() == 0) {
        std::cout << "--No accounts in this bank" << std::endl;
        return ;
    }
    
    for (int i = 0; i < Bank.size(); i++) {
        std::cout << "Account holder name: " << Bank.at(i)->getAccountHolderName() << std::endl;
        std::cout << "Account holder balance: $" << Bank.at(i)->getBalance() << std::endl;
        std::cout << std::endl;
    }
}

void printMenuChoices(const BankAccount *currentUser, bool isLogged) {
        std::cout << "---------------------------" << std::endl;
        std::cout << "Welcome to the Bank!" << std::endl;
        std::cout << "User: " << (isLogged ? currentUser->getAccountHolderName() : "Not Logged In") << std::endl;
        std::cout << "Services:" << std::endl;
        std::cout << "Enter 1: Create an Account" << std::endl;
        std::cout << "Enter 2: Login" << std::endl;
        std::cout << "Enter 3: Logout" << std::endl;
        std::cout << "Enter 4: Deposit" << std::endl;
        std::cout << "Enter 5: Withdraw" << std::endl;
        std::cout << "Enter 6: Print User Details" << std::endl;
        std::cout << "Enter 7: Print all Users" << std::endl;
        std::cout << "Enter -1: Quit" << std::endl;
}

int getMenuChoice(int choice) {
    std::cout << "===> " ; 

    while (!(std::cin >> choice)) {
        std::cin.clear(); // clear the error flags  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "--Invalid input. Not a Valid Option. Try again." << std::endl;
        std::cout << "===> " ; 
    }
    
    // std::cin leaves a \n in the input buffer, so, when a user chooses option 1 to create an account, 
    // getline() will immediately read that newline and result in an empty string.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // so clear the input buffer. 

    return choice;
}

