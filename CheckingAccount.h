#ifndef CHECKINGSACCOUNT_H
#define CHECKINGSACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
    private:
        double transactionFee;
    public:
        CheckingAccount();
        void withdraw(double withdrawAmount) override;
};

#endif
