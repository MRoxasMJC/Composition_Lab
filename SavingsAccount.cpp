
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : BankAccount(), interestRate(0.005) {} // hardcode the interest rate to 0.5%

void SavingsAccount::calculateInterest() {
    double total = getBalance() * interestRate;   
    deposit(total);
}
