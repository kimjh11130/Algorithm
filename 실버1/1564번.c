#include <stdio.h>

int main(void) {
    long long int n, a = 1, b = 1e12;
    scanf("%lld", &n);
    while (n - 1) {
        a *= n--;
        while (a % 10 == 0) a /= 10;
        a = a % b;
    }
    printf("%05lld", a % 100000);
}