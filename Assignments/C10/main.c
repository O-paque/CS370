#include <stdio.h>
#include "sort.h"

int main(int argc, char **argv) {
    int i, j;

    scanf("%d", &i);

    int arr[i];

    for (j = 0; j < i; j++) {
        scanf("%d", &arr[j]);
    }

    sort(arr, i);

    for (j = 0; j < i; j++) {
        printf("%d\n", arr[j]);
    }
}