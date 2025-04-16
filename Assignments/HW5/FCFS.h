#ifndef FCFS_H
#define FCFS_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Process.h"

class FCFS{
    private:
        int time;
        double avgTurnTime, avgWaitTime, throughput;
        void sortVector(std::vector<Process> &processes);
        void printResults();

    public:
        FCFS();
        void run(std::vector<Process> processes);
};

#endif