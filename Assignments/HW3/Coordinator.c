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
    int pipes[ARGS * 2];
    pid_t pids[ARGS];
    int sharedMemoryId;

    for (int i = 0; i < ARGS; i++) {
        sharedMemoryId = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
        int fd[2];
        pipe(fd);
        pid_t pid = fork();
        
        if (pid < 0){
            perror("Fork failed");
        }
        else if (pid > 0){
            close(fd[0]);
            write(fd[1], &sharedMemoryId, sizeof(sharedMemoryId));
            close(fd[1]);

            pids[i] = pid;
            shm[i] = sharedMemoryId;

            printf("Coordinator: forked process with ID %d\n", pid);
            printf("Coordinator: wrote shm ID %d to pipe (%d bytes)\n", 
                sharedMemoryId, sizeof(int));
            
        }
        else {
            close(fd[1]);
            char buffer[8];
            
            int memId;
            read(fd[0], &memId, sizeof(memId));
            close(fd[0]);
            sprintf(buffer, "%d", memId);
            // argv[i+2] to index into argv where the dividends start
            execlp("./checker", buffer, argv[1], argv[i+2], NULL);
            perror("execlp failed");
        }
    }

    int status;
    for (int i = 0; i < ARGS; i++) {
        printf("Coordinator: waiting on chlid process ID %d...\n", pids[i]);
        waitpid(pids[i], &status, 0);

        int *sharedMemPointer = (int*)shmat(shm[i], NULL, 0);
        int result = *sharedMemPointer;

        if (result > 0){
            printf("Coordinator: result 1 read from shared memory: "
                "%d is divisible by %d\n", atoi(argv[i+2]), atoi(argv[1]));
        }
        else {
            printf("Coordinator: result 0 read from shared memory: "
                "%d is not divisible by %d\n", atoi(argv[i+2]), atoi(argv[1]));
        }
       shmctl(*sharedMemPointer, IPC_RMID, NULL);
    }
    printf("Coordinator: exiting.\n");
    return 0;
}