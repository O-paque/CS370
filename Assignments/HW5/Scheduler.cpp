#include <fstream>
#include <sstream>
#include <vector>
#include "Process.h"
#include "FCFS.h"
#include "SJF.h"
#include "PS.h"

using namespace std;

void parse(vector<Process> &processes, ifstream &file);

int main(int argc, char *argv[]) {
    vector<Process> processes;
    ifstream file(argv[argc - 1]);

    FCFS fcfs;
    SJF sjf;
    PS ps;



    parse(processes, file);

    vector<Process> inputFCFS = processes;
    vector<Process> inputSJF = processes;
    vector<Process> inputPS = processes;

    fcfs.run(inputFCFS);
    sjf.run(inputSJF);
    ps.run(inputPS);

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
                    processes.push_back({pid, arrival, burst, priority, -1, burst, 0});
                }
                else {
                    cerr << "Error parsing line: " << line << endl;
                }
        }
    }
}