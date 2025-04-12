#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include "FCFS.h"

// CS370-HW5-Input.csv
// sample.csv

using namespace std;

void parse(vector<tuple<int,int,int,int>> &processes, ifstream &file);

int main(int argc, char *argv[]) {
    vector<tuple<int,int,int,int>> processes;
    ifstream file(argv[argc - 1]);

    parse(processes, file);

    for (const auto& [a, b, c, d] : processes) {
        std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }

}

void parse(vector<tuple<int,int,int,int>> &processes, ifstream &file) {
    string line;
    int pid, arrival, burst, priority;
    char comma;
    if (file.is_open()) {
        while(file >> line){
            istringstream ss(line);
            if (ss >> pid >> comma >> arrival >> comma >> burst >> 
                comma >> priority) {
                    processes.emplace_back(pid, arrival, burst, priority);
                }
                else {
                    cerr << "Error parsing line: " << line << endl;
                }
        }
    }

}