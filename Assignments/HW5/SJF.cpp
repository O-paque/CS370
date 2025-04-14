#include "SJF.h"

using namespace std;

SJF::SJF(){
    time = 0;
    avgTurnTime = 0;
    avgWaitTime = 0;
    throughput = 0;
}

void SJF::run(std::vector<Process> processes) {
    printResults();
}

/*
@brief  Formatted print statement for the autograder.
*/
void SJF::printResults(){
    cout << "--- SJFP ---" << fixed << setprecision(3) << endl;
    cout << "Average Turnaround Time: " << avgTurnTime << endl;
    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Throughput: " << throughput << endl;
}