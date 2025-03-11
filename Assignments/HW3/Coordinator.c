#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char **argv) {
    if (argc < 3){
        printf("Need at least 2 args\n");
        return 1;
    }
    int ARGS = argc - 2;
    int shm[ARGS];
    pid_t pids[ARGS];
    int fd[2];

    for (int i = 0; i < ARGS; i++) {
        int sharedMemoryId = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
        pipe(fd);

        pid_t pid = fork();
        
        if (pid < 0){
            perror("Fork failed");
        }
        else if (pid > 0){
            close(fd[0]);
            printf("Coordinator: forked process with ID %d.\n", pid);
            write(fd[1], &sharedMemoryId, sizeof(sharedMemoryId));
            printf("Coordinator: wrote shm ID %d to pipe (%d bytes)\n", 
                sharedMemoryId, sizeof(int));
            close(fd[1]);
            pids[i] = pid;
            shm[i] = sharedMemoryId;
        }
        else {
            char buffer[8];
            sprintf(buffer, "%d", fd[0]);
            execlp("./checker", buffer, argv[1], argv[i+2], NULL);
            perror("execlp failed");
        }
    }

    for (int i = 0; i < ARGS; i++) {
        
        printf("Coordinator: waiting on child process ID %d...\n", pids[i]);
        wait(NULL);

        int *sharedMemPointer = (int*)shmat(shm[i], NULL, 0);
        int result = *sharedMemPointer;

        if (result > 0){
            printf("Coordinator: result 1 read from shared memory: "
                "%d is divisible by %d.\n", atoi(argv[i+2]), atoi(argv[1]));
        }
        else {
            printf("Coordinator: result 0 read from shared memory: "
                "%d is not divisible by %d.\n", atoi(argv[i+2]), atoi(argv[1]));
        }
       shmctl(*sharedMemPointer, IPC_RMID, NULL);
    }
    printf("Coordinator: exiting.\n");
    return 0;
}