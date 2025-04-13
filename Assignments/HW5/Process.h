#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int pid, arrival, burst, priority;
    int startTime = 0;
    int finishTime = 0;
    int turnTime = 0;
    int waitTime = 0;
};

#endif