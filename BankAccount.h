#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
class BankAccount {
    private:
        std::string accountNumber;
        std::string accountHolderName;
        double balance; // in dollars
    public:
        BankAccount();
        BankAccount(std::string accHolderNameInp, double balanceInp = 0.00);
        
        // not really sure why we need these yet so I will comment them out
        virtual ~BankAccount();
        // BankAccount(const BankAccount &other);
    
        void setAccountHolderName(std::string accHolderNameInp);
        virtual void deposit(double depositAmount);
        virtual void withdraw(double withdrawAmount);
        
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
};
#endif
