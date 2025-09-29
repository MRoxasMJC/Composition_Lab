#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
    private:
        double interestRate;
    public:
        SavingsAccount();
        void calculateInterest();
};

#endif

