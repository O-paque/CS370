#ifndef PS_H
#define PS_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Process.h"

class PS {
    private:
        int time;
        double avgTurnTime, avgWaitTime, throughput;
        void printResults();

    public:
        PS();
        void run(std::vector<Process> processes);
};

#endif