#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    printf("Checker process [%d]: Starting.\n", getpid());
    int divisor = atoi(argv[0]);
    int dividend = atoi(argv[1]);
    sleep(1);

    if (dividend % divisor != 0){
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", 
            getpid(), dividend, divisor);

        printf("Checker process [%d]: Returning 0.\n", getpid());
        return 0;
    }

    printf("Checker process [%d]: %d *IS* divisible by %d.\n", 
        getpid(), dividend, divisor);

    int result = dividend / divisor;

    printf("Checker process [%d]: Returning %d.\n", getpid(), result);
    return result;
}