#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int pid, arrival, burst, priority, startTime, remainingTime, finishTime;
};

#endif