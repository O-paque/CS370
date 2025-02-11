#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class BankAccount{
    private:
        double total_balance;

    public:
        BankAccount();
        double balance();
        void deposit(double amount);
        void withdraw(double amount);
};

#endif