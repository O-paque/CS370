#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n);

int main(int argc, char **argv) {
    int n;

    scanf("%d", &n);

    bool prime_flag[n];
    prime_flag[0] = false;
    prime_flag[1] = false;

    for(int i = 2; i <= n; i++){
        //prime_flag[i] = false;
        if (is_prime(i)){
            //prime_flag[i] = true;
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