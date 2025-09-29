#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "Transaction.h"

class BankAccount {
    private:
        std::string accountNumber;
        std::string accountHolderName;
        double balance; // in dollars
        std::vector<Transaction> transactionHistory;
    public:
        BankAccount();
        BankAccount(std::string accHolderNameInp, double balanceInp = 0.00);
        
        // not really sure why we need these yet so I will comment them out
        virtual ~BankAccount();
        // BankAccount(const BankAccount &other);
    
        void setAccountHolderName(std::string accHolderNameInp);
        virtual void deposit(double depositAmount);
        virtual void withdraw(double withdrawAmount);
        void saveTransaction(std::string name, std::string type, double amount);
        
        std::string getAccountNumber() const;
        std::string getAccountHolderName() const;
        double getBalance() const;
        
        BankAccount& operator+=(double amount);
        BankAccount& operator-=(double amount);
        BankAccount& operator=(const BankAccount &other);
        bool operator==(const BankAccount &other) const;
        bool operator>(const BankAccount &other) const;
        bool operator<(const BankAccount &other) const;
        
        static void printAccount(const BankAccount *&currentUser);
        static BankAccount createAccountFromInput(bool isLogged);
        void printHistory(); 
};
#endif
