#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h>

// ./run.sh 2 4 5 6 7

int main(int argc, char **argv) {
    
    //Loop to fork(), exec(), and wait() one at a time
    for (int i = 2; i < 6; i++){
        pid_t pid = fork();

        switch (pid) {
            case -1:
                perror("Coordinator: Fork failed.\n");
                break;
            case 0:
                //String passed to execlp needs to match object file in Makefile
                execlp("./checker", argv[1], argv[i], NULL);
                perror("Coordinator: execlp failed.");
                break;
            default:
                printf("Coordinator: forked process with ID %d.\n", pid);

                int status;
                printf("Coordinator: waiting for process [%d].\n", pid);
                wait(&status);

                int result = WEXITSTATUS(status);
                printf("Coordinator: child process %d returned %d.\n", 
                    pid, result);

                break;
        }
    }
    printf("Coordinator: exiting.\n");
    return 0;
}