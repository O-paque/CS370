#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n);

int main(int argc, char **argv) {
    int n;

    scanf("%d", &n);

    for(int i = 2; i <= n; i++){
        if (is_prime(i)){
            printf("%d\n", i);
        }
    }


}

bool is_prime(int n) {
    for(int i = 2; i < n; i++) {
        if (n % i == 0){
            return false;
        }
    }
    return true;
}