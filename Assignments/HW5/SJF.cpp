#include "SJF.h"

using namespace std;

/*
@brief  Sort the Process vector primarily by arrival time, then by priority

@param  processes: The data structure holding the process value
*/
void SJF::sortVector(vector<Process> &processes) {
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b) {
        if (a.arrival == b.arrival) {
            return a.priority < b.priority;
        }
        return a.arrival < b.arrival;
    });
}

SJF::SJF(){
    time = 0;
    avgTurnTime = 0;
    avgWaitTime = 0;
    throughput = 0;
}

/*
@brief  Emulate the SJF scheduling algorithm with preemption, which will find the shortest job
available at the top of each clock cycle and run it to completion.

@param  processes: The data structure holding the process values.
*/
void SJF::run(std::vector<Process> processes) {
    sortVector(processes);
    int complete = 0;   
    int leastTime, leastIndex;
    
    // Loop until all processes in the vector reach a remainingTime of 0
    while (complete < processes.size()) {
        leastTime = 10000;   // Initialize to a large burst to always find a smaller one from input

        // Find the index of the shortest remaining process to run that has "arrived"
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].arrival <= time &&
                processes[i].remainingTime > 0 &&
                processes[i].remainingTime < leastTime) {
                    leastTime = processes[i].remainingTime;
                    leastIndex = i;
            }
        }

        // Reference to the shortest process
        Process& currentExecution = processes[leastIndex];

        if (currentExecution.startTime == -1){
            currentExecution.startTime = time;
        }

        // Single quantum simulation
        time++;
        currentExecution.remainingTime--;

        if (currentExecution.remainingTime == 0) {
            currentExecution.finishTime = time;
            avgWaitTime += currentExecution.startTime - currentExecution.arrival;
            avgTurnTime += currentExecution.finishTime - currentExecution.arrival;
            complete++;
        }
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
void SJF::printResults(){
    cout << "--- SJFP ---" << fixed << setprecision(3) << endl;
    cout << "Average Turnaround Time: " << avgTurnTime << endl;
    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Throughput: " << throughput << endl;
}