#ifndef POINTERS_H
#define POINTERS_H

float* new_float(){
    float* f = malloc(sizeof(float));
    *f = 0.0;
    return f;
}

void swap (float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

#endif