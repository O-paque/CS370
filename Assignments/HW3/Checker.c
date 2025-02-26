#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char **argv) {
    printf("Checker process [%d]: starting.\n", getpid());
    //sleep(1);
    int fd = atoi(argv[0]);
    int pipe = atoi(argv[0]);
    int divisor = atoi(argv[1]);
    int dividend = atoi(argv[2]);
    read(fd, &pipe, sizeof(pipe));

    printf("Checker process [%d]: read 4 bytes containing shm ID %d\n", getpid(), pipe);

    int *sharedMemPointer = (int*)shmat(pipe, NULL, 0);
    //*sharedMemPointer = 42;

    if (dividend % divisor != 0){
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", 
            getpid(), dividend, divisor);

            *sharedMemPointer = 0;

            printf("Checker process [%d]: wrote result (0) to shared memory.\n", getpid());
        
    }
    else {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", 
            getpid(), dividend, divisor);
    
        *sharedMemPointer = 1;
    
        printf("Checker process [%d]: wrote result (1) to shared memory.\n", getpid());
    }



    shmdt(sharedMemPointer);

    
    return 0;
}