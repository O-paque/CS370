#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include "Process.h"
#include "FCFS.h"

// CS370-HW5-Input.csv
// sample.csv

using namespace std;

void parse(vector<Process> &processes, ifstream &file);
void printValues(vector<Process> &processes);
void printResults(FCFS &fcfs);

int main(int argc, char *argv[]) {
    vector<Process> processes;
    ifstream file(argv[argc - 1]);

    FCFS fcfs;

    parse(processes, file);
    printValues(processes);

    printResults(fcfs);

    return 0;
}

/*
@brief  Parse the input .csv file and input lines into a vector of Processes

@param  processes: The data structure that will hold the process values
@param  file: The file to be read from
*/
void parse(vector<Process> &processes, ifstream &file) {
    string line;
    int pid, arrival, burst, priority;
    char comma;
    if (file.is_open()) {
        while(file >> line){
            istringstream ss(line);
            if (ss >> pid >> comma >> arrival >> comma >> burst >> 
                comma >> priority) {
                    processes.push_back({pid, arrival, burst, priority});
                }
                else {
                    cerr << "Error parsing line: " << line << endl;
                }
        }
    }
}

/*
@brief  Print the original values that were read into the Process vector

@param  processes: The data structure holding the process values
*/
void printValues(vector<Process> &processes) {
    for (const auto& p: processes) {
        cout << p.pid << ' ' << p.arrival << ' ' << 
            p.burst << ' ' << p.priority << endl;
    }
}

/*
@brief  Formatted output required by assignment parameters 
        to show algorithm performance

@param  fcfs: The FCFS algorithm
*/
void printResults(FCFS &fcfs) {
    cout << "--- FCFS ---\nAverage Turnaround Time: " << fcfs.getTurn() <<
        "\nAverage Waiting Time: " << fcfs.getWait() << 
        "\nThroughput: " << fcfs.getThroughput() << endl;
}