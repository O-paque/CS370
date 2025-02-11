#include "bank_account.h"

using namespace std;

BankAccount::BankAccount(){
    total_balance = 0.0;
}

double BankAccount::balance(){
    return total_balance;
}

void BankAccount::deposit(double amount){
    if(amount > 0) {
        total_balance += amount;
    }
}

void BankAccount::withdraw(double amount){
    if(amount <= total_balance && amount > 0){
        total_balance -= amount;
    }
}

