#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

// testers
void testBankAccountClass();
void testBankAccountEqualAccNum();
void testBankAccountGreaterLessThan();
void testCheckingAndSavingsAccount();
//

// void createAccount(std::vector<BankAccount> &Bank, bool isLogged); 
void createAccountInput(BankAccount *account);
void createAccount(std::vector<BankAccount*> &Bank, bool isLogged);
void selectAccount(std::vector<BankAccount*> &Bank, BankAccount *&currentUser, bool &isLogged);
void logout(BankAccount *&currentUser, bool &isLogged);
void makeDeposit(BankAccount *&currentUser, bool isLogged);
void makeWithdrawal(BankAccount *&currentUser, bool isLogged);
void printUserBalance(const BankAccount *currentUser, bool isLogged);
void printCurrentUser(const BankAccount *currentUser, bool isLogged);
void printAllUsers(const std::vector<BankAccount*> Bank);
void printMenuChoices(const BankAccount *currentUser, bool isLogged);
int getMenuChoice(int choice);

#endif
