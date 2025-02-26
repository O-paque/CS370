#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char **argv) {
    int fd = atoi(argv[0]);
    int pipe = atoi(argv[0]);

    read(fd, &pipe, sizeof(pipe));

    int *sharedMemPointer = (int*)shmat(pipe, NULL, 0);

    *sharedMemPointer = 42;

    shmdt(sharedMemPointer);

    printf("Dummy [%d]: shm ID received: %d\n", getpid(), pipe);
    return 0;
}