#include <stdio.h>

int main(int argc, char **argv) {
    int a, i;

    scanf("%d", &a);

    for (i = 1; i <= 10; i++) {
        printf("%d\n", a * i);
    }
    
    return 0;
}