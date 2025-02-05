#include <stdio.h>
#include <stdlib.h>
#include "pointers.h"

int main(int argc, char **argv) {
    float* f1 = new_float();
    float* f2 = new_float();

    scanf("%f", f1);
    scanf("%f", f2);

    swap(f1, f2);

    printf("%f %f\n",*f1, *f2);
}