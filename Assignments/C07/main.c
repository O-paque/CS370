#include <stdio.h>

int main(int argc, char **argv) {
    int i, j;

    scanf("%d", &i);

    int arr[i];

    for (j = 0; j < i; j++) {
        scanf("%d", &arr[j]);
    }

    for (j = i-1; j > -1; j--) {
        printf("%d\n", arr[j]);
    }

    return 0;
}