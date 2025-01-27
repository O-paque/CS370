#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int a;
    if (argc <= 2){
        a = atoi(argv[1]);
    }
    else {
        printf("Only one argument needed");
        return 1;
    }
    if (a % 2 == 0) {
        printf("even\n");
    }
    else {
        printf("odd\n");
    }
    return 0;
}