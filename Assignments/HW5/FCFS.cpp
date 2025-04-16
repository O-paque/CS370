#include "FCFS.h"

using namespace std;

/*
@brief  Sort the Process vector primarily by arrival time, then by priority

@param  processes: The data structure holding the process value
*/
void FCFS::sortVector(vector<Process> &processes) {
    stable_sort(processes.begin(), processes.end(), [](const Process &a, const Process &b) {
        return a.arrival < b.arrival;
    });
}

FCFS::FCFS() {
    time = 0;
    avgTurnTime = 0;
    avgWaitTime = 0;
    throughput = 0;
}

/*
@brief  Emulate the FCFS scheduling algorithm, which runs a process based off of arival time for
its enitre burst duration. 

@param  processes: The data structure holding the process values.
*/
void FCFS::run(vector<Process> &processes) {
    sortVector(processes);

    // Run each process from the sorted vector in FCFS fashion
    for (auto &p : processes) {
        p.startTime = max(time, p.arrival);
        p.finishTime = p.startTime + p.burst;
        avgWaitTime += p.finishTime - p.arrival - p.burst;
        avgTurnTime += p.finishTime - p.arrival;
        time = p.finishTime;
    }

    // Compute the performance metrics
    avgWaitTime = avgWaitTime / processes.size();
    avgTurnTime = avgTurnTime / processes.size();
    throughput = processes.size() / (double) time;

    printResults();
}

/*
@brief  Formatted print statement for the autograder.
*/
void FCFS::printResults(){
    cout << "--- FCFS ---" << fixed << setprecision(3) << endl;
    cout << "Average Turnaround Time: " << avgTurnTime << endl;
    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Throughput: " << throughput << endl;
}