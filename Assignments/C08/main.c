#include <stdio.h>

int main(int argc, char **argv) {
    char c[1000];
    char vowels[10] = {'a','A','e','E','i','I','o','O','u','U'};
    char h;
    int counter = 0;

    while (h != ' ') {
        scanf("%c", &h);
        for (int i = 0; i < sizeof(vowels); i++){
            if (vowels[i] == h) {
                counter++;
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}