#include "PS.h"

using namespace std;

PS::PS(){
    time = 0;
    avgTurnTime = 0;
    avgWaitTime = 0;
    throughput = 0;
}

/*
@brief  Emulate the PS scheduling algorithm with preemption, which will find
the highest priority process available at the top of each clock cycle and run it
to compleiton

@param  processes: The data structure holding the process values.
*/
void PS::run(std::vector<Process> &processes) {
    int complete = 0;   
    int leastPriority, leastIndex, leastArrival, leastPID;
    
    // Loop until all processes in the vector reach a remainingTime of 0
    while (complete < processes.size()) {
        leastPriority = 100; // Lowest priority in input set is <= 50
        leastArrival = 10000;
        leastPID = 10000;
        leastIndex = -1;

        // Find the index of the highest priority process to run
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].arrival <= time && processes[i].remainingTime > 0) {
                if (processes[i].priority < leastPriority ||
                    processes[i].priority == leastPriority && processes[i].arrival < leastArrival ||
                    processes[i].priority == leastPriority && processes[i].arrival == leastArrival &&
                    processes[i].pid < leastPID) {
                        leastPriority = processes[i].priority;
                        leastIndex = i;
                        leastArrival = processes[i].arrival;
                        leastPID = processes[i].pid;
                    }
            }
        }

        if (leastIndex == -1){
            time++;
            continue;
        }

        // Reference to the shortest process
        Process& exe = processes[leastIndex];

        if (exe.startTime == -1){
            exe.startTime = time;
        }

        // Single quantum simulation
        time++;
        exe.remainingTime--;

        if (exe.remainingTime == 0) {
            exe.finishTime = time;
            avgWaitTime += exe.finishTime - exe.arrival - exe.burst;
            avgTurnTime += exe.finishTime - exe.arrival;
            complete++;
        }
    }

    // Compute the performance metrics
    avgWaitTime = avgWaitTime / static_cast<double>(processes.size());
    avgTurnTime = avgTurnTime / static_cast<double>(processes.size());
    throughput = processes.size() / (double) time;

    printResults();
}

/*
@brief  Formatted print statement for the autograder.
*/
void PS::printResults(){
    cout << "--- Priority ---" << fixed << setprecision(3) << endl;
    cout << "Average Turnaround Time: " << avgTurnTime << endl;
    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Throughput: " << throughput << endl;
}