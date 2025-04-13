#include "FCFS.h"

using namespace std;

FCFS::FCFS() {
    avgTurnTime = 0;
    avgWaitTime = 0;
    throughput = 0;
}

int FCFS::getTurn() {
    return avgTurnTime;
}

int FCFS::getWait() {
    return avgWaitTime;
}

int FCFS::getThroughput() {
    return throughput;
}