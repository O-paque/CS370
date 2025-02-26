#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// ./run.sh 2 4 5 6 7

int main(int argc, char **argv) {
    if (argc < 3){
        printf("Need at least 2 args\n");
        return 1;
    }
    int ARGS = argc - 2;

    int fd[2];
    int shm[ARGS];
    int pipes[ARGS * 2];
    pid_t pids[ARGS];
    int sharedMemoryId;

    for (int i = 0; i < ARGS; i++) {
        sharedMemoryId = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
        pipe(fd);
        pid_t pid = fork();
        
        if (pid < 0){
            perror("Fork failed");
        }
        else if (pid > 0){
            pids[i] = pid;
            shm[i] = sharedMemoryId;
            printf("Coordinator: forked process with ID %d\n", pid);
            close(fd[0]);
            write(fd[1], &sharedMemoryId, sizeof(sharedMemoryId));
            printf("Coordinator: wrote shm ID %d to pipe (%d bytes)\n", sharedMemoryId, sizeof(int));
            close(fd[1]);
        }
        else {
            sleep(1);
            char buffer[8];
            sprintf(buffer, "%d", fd[0]);
            // argv[i+2] to index into argv where the dividends start
            execlp("./checker", buffer, argv[1], argv[i+2], NULL);
            perror("execlp failed");
        }
    }
    sleep(1);
    int status;
    for (int i = 0; i < ARGS; i++) {
        printf("Coordinator: waiting on chlid process ID %d...\n", pids[i]);
        wait(&status);

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
 
    
    

    
    


    
    return 0;
}

    // pid_t pid_1 = fork();

    // if (pid_1 < 0) {
    //     perror("Coordinator: Fork failed.\n");
    // }
    // else if (pid_1 > 0) {   // Parent Process
    //     // Parent process does not need read end of the pipe
    //     close(fd[0]);

    //     // Unspecific Integer to pass through the pipe
    //     int numb = 123;
 
    //     // Write int to pipe
    //     write(fd[1], &numb, sizeof(numb));
 
    //     //Close writing end of pipe, may be different needs for HW3?
    //     close(fd[1]);
    // }
    // else {  // Child Process
    //     // Create a buffer
    //     char buffer[8];

    //     // Write the address of the read end of the pipe to the buffer
    //     sprintf(buffer, "%d", fd[0]);

    //     // Create the child process and pass the buffer to it
    //     execlp("./checker", buffer, NULL);
    // }

    // Example of creating shared memory from video
    // int sharedMemoryId = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    // This is what will be passed by the pipe from parent to child?

    //Similar to HW2, wait for child to finish

    // Attach to shared memory
    // int *sharedMemoryPointer = (int*)shmat(sharedMemoryID, NULL, 0);

    // Read from shared memory by dereferencing pointer

    // Destroy shared memory
    // shmctl(*sharedMemoryPointer, IPC_RMID, NULL);



    /*              Latest
    int fd[2];
    int shm[4];
    int pipes[8];
    pid_t pid;
    pid_t pids[4];
    for (int i = 2; i < 6; i++){
        pipe(fd);
        shm[i-2] = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
        pipes[i*2] = fd[0];
        pipes[i*2 +1] = fd[1];
        pids[i-2] = fork();

        // if (pid < 0){
        //     printf("Fork failed\n");
        // }
        // else if (pid > 0) {
            
        //     // Parent process does not need read end of the pipe
        //     close(fd[0]);

        //     // Create shared memory segment
        //     int sharedMemoryId = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
            
        //     // Write shared memory to pipe
        //     write(fd[1], &sharedMemoryId, sizeof(sharedMemoryId));

        //     printf("Coordinator: wrote shm ID %d to pipe (%d bytes)\n", sharedMemoryId, sizeof(int));

        //     //Close writing end of pipe, may be different needs for HW3?
        //     close(fd[1]);
        // }
        // else {
        //     printf("Coordinator: forked process with ID %d\n", getpid());

        //     // Create a buffer
        //     char buffer[8];

        //     // Write the address of the read end of the pipe to the buffer
        //     sprintf(buffer, "%d", fd[0]);

        //     // Create the child process and pass the buffer to it
        //     execlp("./checker", buffer, NULL);
        // }

        if (pids[i-2] < 0){
            printf("Fork failed\n");
        }
        else if (pids[i-2] > 0){
            //printf("Coordinator: Fork suceeded\n");
            printf("Coordinator: forked process with ID %d.\n", pids[i-2]);
            
            write(pipes[i*2 + 1], shm[i-2], sizeof(int));
            printf("Coordinator: wrote shm ID %d to pipe\n", shm[i-2]);
            close(pipes[i*2 + 1]);
        }
        else {
            wait(10);
            char buffer[8];
            // Write the address of the read end of the pipe to the buffer
            sprintf(buffer, "%d", fd[0]);
            close(fd[i*2]);
            execlp("./dummy", buffer, NULL);
            
        }
    }

    wait(3);
    
    for (int i = 2; i < 6; i++){
        int status;
        printf("Coordinator: waiting on chlid process ID %d...\n", pids[i-2]);
        wait(&status);
        int result = WEXITSTATUS(status);
        printf("Coordinator: child process %d returned %d.\n", 
            pid, result);
    }

    

*/