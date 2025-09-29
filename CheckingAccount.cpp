#include <iostream>
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() : BankAccount(), transactionFee(1.50) {};

void CheckingAccount::withdraw(double withdrawAmount) {
    if ((getBalance() - withdrawAmount - transactionFee) < 0) {
        std::cout << "--Insufficient Funds!" << std::endl;
        return;
    }

    std::cout << "--Transaction fee of $" << transactionFee << " applied." << std::endl;
    BankAccount::withdraw(withdrawAmount + transactionFee);
}


