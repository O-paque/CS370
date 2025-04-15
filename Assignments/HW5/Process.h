#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int pid, arrival, burst, priority;
    int startTime = 0;
    int remainingTime = 0;
    int finishTime = 0;
};

#endif