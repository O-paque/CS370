#include <stdio.h>

int notSpace (char c);

int main(int argc, char **argv) {
    char c[1000];
    char vowels[10] = {'a','A','e','E','i','I','o','O','u','U'};
    char h;
    int counter = 0;

    while (notSpace(h)) {
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

int notSpace(char c) {
    char s[6] = {' ', '\t', '\n', '\v', '\f', '\r'};
    for (int i = 0; i < sizeof(s); i++){
        if (s[i] == c){
            return 0;
        }
    }
    return 1;
}