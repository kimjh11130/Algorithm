#include <stdio.h>

int n, i;

int isPrime(int a) {
    if (a == 1) return 0;
    for (int j = 2; j * j <= a; j++) {
        if (a % j == 0) return 0;
    }
    return 1;
}

void back(int a) {
    if (i == n) {
        printf("%d\n", a);
    } else {
        for (int j = 1; j < 10; j++) {
            if (isPrime(a * 10 + j)) {
                i++, back(a * 10 + j), i--;
            }
        }
    }
}

int main(void) {
    scanf("%d", &n);
    back(0);
}