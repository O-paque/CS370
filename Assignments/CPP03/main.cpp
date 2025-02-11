#include <iostream>
#include <string>
#include "bank_account.h"

using namespace std;

enum bank_oper {
    BALANCE, DEPOSIT, WITHDRAW, EXIT
};

bank_oper parseOperation(string const &op, double& value);

int main(int argc, char *argv[]) {
    double value;
    string s;
    BankAccount acc;
    while (getline(cin, s)){
        value = 0;
        bank_oper operation = parseOperation(s, value); 
        switch (operation){
            case BALANCE:
                cout << acc.balance() << '\n';
                break;
            case DEPOSIT:
                acc.deposit(value);
                break;
            case WITHDRAW:
                acc.withdraw(value);
                break;
            default:
                return 0;
        }
    }
    return 0;
}

bank_oper parseOperation(string const &op, double& value){
    int space = op.find(' ');
    if(space != -1){
        string left = op.substr(0,space);
        value = stod(op.substr(space));

        if (left == "deposit"){
            return DEPOSIT;
        }
        return WITHDRAW;
    }

    if (op == "balance") return BALANCE;
    return EXIT;
}