#include <stdio.h>

int main(void) {
    long long int a, b, c, res = 1;
    scanf("%lld %lld %lld", &a, &b, &c);
    while (b > 0) {
        if (b % 2 == 1) res = res * a % c;
        a = a * a % c;
        b /= 2;
    }
    printf("%lld", res % c);
}