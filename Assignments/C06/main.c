#include <stdio.h>

int main(int argc, char **argv) {
    int i;
    unsigned long long a;

    scanf("%lld", &a);

    i = a;
    while (i > 1) {
        a *= i - 1;
        i--;
    }
    
    printf("%lld\n", a);

    return 0;
}