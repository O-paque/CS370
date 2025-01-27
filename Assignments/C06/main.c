#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int i;
    unsigned long long a;

    if (argc <= 2){
        a = atoi(argv[1]);
    }

    i = a;
    while (i > 1) {
        a *= i - 1;
        i--;
    }
    
    printf("%lld\n", a);

    return 0;
}