#include <stdio.h>

int main(int argc, char **argv) {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    if (a > b) {
        printf("%d\n", a);
    }
    else if (b > a) {
        printf("%d\n", b);
    }
    else {
        printf("equal\n");
    }
    return 0;
}