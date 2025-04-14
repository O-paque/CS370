#ifndef SJF_H
#define SJF_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Process.h"

class SJF{
    private:
        int time;
        double avgTurnTime, avgWaitTime, throughput;
        void sortVector(std::vector<Process> &processes);
        void printResults();

    public:
        SJF();
        void run(std::vector<Process> processes);
};

#endif