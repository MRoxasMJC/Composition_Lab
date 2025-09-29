# Inheritance_Lab: Bank Account System

## Overview
This is a simple C++ banking system demonstrating **inheritance, polymorphism, and operator overloading**.  
Users can create **Checking** and **Savings** accounts, deposit, withdraw, and view account details.

The system uses:
- `BankAccount` (base class)  
- `CheckingAccount` (derived, applies a transaction fee)  
- `SavingsAccount` (derived, calculates interest)  
- A vector of `BankAccount*` pointers to store multiple account objects.  

---

## Features
- Create a **Checking** or **Savings** account  
- Deposit and withdraw money  
- Display your account details  
- Print all accounts in the bank  
- Logout and switch accounts  

---

## How to Run
1. **Compile the project** using `g++`:

```bash
g++ Bank.cpp BankAccount.cpp CheckingAccount.cpp SavingsAccount.cpp menuFunctions.cpp -o Bank
```
2. **How to Run**
```bash
./Bank   # macOS / Linux
Bank.exe # Windows
```

---
## User Instructions
### Main Menu
When you run the program you will see this:
```
---------------------------
Welcome to the Bank!
User: Not Logged In
Services:
Enter 1: Create an Account
Enter 2: Login
Enter 3: Logout
Enter 4: Deposit
Enter 5: Withdraw
Enter 6: Print User Details
Enter 7: Print all Users
Enter -1: Quit
```
**Option 1: Creating an Account**

Choose 1.

Select the account type:

- Enter 1 for Savings Account

- Enter 2 for Checking Account

Enter your username and initial balance when prompted.

Savings accounts automatically add interest to the initial balance.
Checking accounts apply a $1.50 transaction fee on withdrawals.

**Option 2: Login**

Choose 2. 

* Enter your username.

* If the username exists, you are now logged in.

**Option 3: Logout**

Choose 3.

* You will be logged out and can switch accounts.

**Option 4: Deposit**

Choose 4.

* Enter the amount to deposit.

* Your balance is updated.

**Option 5: Withdraw**

Choose 5.

* Enter the amount to withdraw.

* For Checking Accounts, a transaction fee will be applied automatically.

* Insufficient funds are rejected.

**Option 6: Print User Details**

Choose 6.

* Displays your account name, account number, and balance.

**Option 7: Print All Users** 

Choose 7.

* Displays all accounts in the bank and their balances.

**Quit**

* Enter -1 to exit the program.
---

