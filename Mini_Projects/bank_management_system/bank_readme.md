# ATM Management System in C

This is a console-based ATM management system implemented in C. It supports both user and admin functionalities.

## Features

### User Features
1. Login with a 5-digit PIN.
2. Check account balance.
3. Withdraw money.
4. Deposit money.
5. View transaction history.
6. Change PIN.
7. Logout.

### Admin Features
1. View all accounts.
2. Create a new account.
3. Delete an account.
4. View total bank balance.
5. Logout.

## How it Works

- The system stores account details (name, PIN, balance, and transaction history) in memory using structures.
- Users can perform actions on their accounts after successful PIN authentication.
- Admin can manage all accounts and view bank-wide details.
- Transactions are recorded with the date using the `__DATE__` macro.

## How to Use

1. Compile the program using a C compiler.
2. Run the executable.
3. Choose either user login or admin login.
4. Follow the on-screen menu to perform desired actions.
5. To exit, select the logout or exit options.
