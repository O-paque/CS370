#include <iostream>
#include <string>

using namespace std;

enum calc_oper {
    ADD, SUB, DIV, MUL
};

double calculate(string &s);
calc_oper parseOperator(string const &op);

int main(int argc, char *argv[]) {
    string s;

    while(getline(cin, s)){
        if(s == "exit"){
            return 0;
        }

        double total = calculate(s);
        
        cout << total << "\n";
    }
    return 0;
}

double calculate (string &s) {
    int space = s.find(' ');
    double left = stoi(s.substr(0,space));
    double right = stoi(s.substr(space+2));
    string oper = s.substr(space + 1, 1);

    calc_oper operation = parseOperator(oper);

    switch (operation) {
        case ADD:
            return left + right;
        case SUB:
            return left - right;
        case DIV:
            return left / right;
        default:
            return left * right;
    }
}

calc_oper parseOperator(string const &op){
    if (op == "+") return ADD;
    if (op == "-") return SUB;
    if (op == "/") return DIV;
    return MUL;
}