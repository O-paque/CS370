#ifndef FCFS_H
#define FCFS_H

class FCFS{
    private:
        int avgTurnTime, avgWaitTime, throughput;

    public:
        FCFS();
        int getTurn();
        int getWait();
        int getThroughput();
};

#endif