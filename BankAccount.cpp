#include <iostream>
#include <string>
#include "BankAccount.h"
#include "Transaction.h"

// define special members of BankAccount
BankAccount::BankAccount() { // default constructor sets accountHolderName, accountNumber, and balance
    accountNumber = std::to_string(rand() + 1000000);  //generate a random account number starting at 100000
    
    accountHolderName = "No Name";
    balance = 0.00;
}

BankAccount::BankAccount(std::string accHolderNameInp, double balanceInp) {
    accountNumber = std::to_string(rand() + 1000000); // again, generate a random account number for the user starting at 1000000. The user does not get to determine their account holder number.
    
    accountHolderName = accHolderNameInp;
    balance = balanceInp;
}

BankAccount::~BankAccount() {
    // nothing to clean up here; no dynamic memory. 
}

// define member functions of BankAccount
void BankAccount::setAccountHolderName(std::string accHolderNameInp) { accountHolderName = accHolderNameInp; }

void BankAccount::saveTransaction(std::string name, std::string type, double amount) {
    // calculate time. 
    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    std::string strTime = std::ctime(&t_c);
    
    // save the transaction and push it to the vector. 
    Transaction t;
    t.name = accountHolderName;
    t.type = type;
    t.amount = amount;
    t.timestamp = strTime;
    transactionHistory.push_back(t);
} 

void BankAccount::deposit(double depositAmount) { 
    balance += depositAmount; 
    saveTransaction(getAccountHolderName(), "Deposit", depositAmount);
}
    
void BankAccount::withdraw(double withdrawAmount) { 
    if ((balance - withdrawAmount) < 0) {
        std::cout << "Insufficient Funds!" << std::endl;
        return; 
    }
    
    balance -= withdrawAmount; 
    saveTransaction(getAccountHolderName(), "Withdrawal", withdrawAmount);
    std::cout << "--Withdrawal of $" << withdrawAmount << " successful." << std::endl;
}

std::string BankAccount::getAccountNumber() const { return accountNumber; }
std::string BankAccount::getAccountHolderName() const { return accountHolderName; }
double BankAccount::getBalance() const { return balance; }

BankAccount& BankAccount::operator=(const BankAccount &other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;
}

BankAccount& BankAccount::operator+=(double depositInp) { // use the existing deposit function.
    this->deposit(depositInp);
    return *this; 
}

BankAccount& BankAccount::operator-=(double withdrawInp) { // use the existing withdraw function
    this->withdraw(withdrawInp);
    return *this;
}

bool BankAccount::operator==(const BankAccount &other) const {
    return this->getAccountNumber() == other.getAccountNumber();
}

bool BankAccount::operator>(const BankAccount &other) const {
    return this->getBalance() > other.getBalance();
}

bool BankAccount::operator<(const BankAccount &other) const {
    return this->getBalance() < other.getBalance();
}

void BankAccount::printAccount(const BankAccount *&currentUser) {
    std::cout << "Account Name: " << currentUser->getAccountHolderName() << std::endl;
    std::cout << "Account Number: " << currentUser->getAccountNumber() << std::endl;
    std::cout << "Balance: $" << currentUser->getBalance() << std::endl;
}

BankAccount BankAccount::createAccountFromInput(bool isLogged) {
    BankAccount account; 
    std::string nameInp;
    double balanceInp;
    
    if (!isLogged) {
        std::cout << "Enter New User Name and Balance: " << std::endl;
        std::getline(std::cin, nameInp);
        std::cin >> balanceInp;
        std::cout << "--Account Creation Successful." << std::endl;
        
        // validate input
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flags  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "--Invalid input Not a Valid User Name. Try again." << std::endl;
            return BankAccount();
        }
        
        account.setAccountHolderName(nameInp);
        account.deposit(balanceInp);
        return account;
    } else {
        std::cout << "--You are already logged in! Logout to create a new account." << std::endl;
        return BankAccount();
    }
}

void BankAccount::printHistory() {
    if (transactionHistory.size() == 0) {
        std::cout << "--You have not made any transactions!" << std::endl;
    }
    
    for (const auto& transaction : transactionHistory) {
        std::cout << "--Transaction Type: " << transaction.type << std::endl;
        std::cout << "--Amount: $"  << transaction.amount << std::endl;
        std::cout << "--Time of $" << transaction.type << ": " << transaction.timestamp << std::endl; 
    }
}
