#include <stdio.h>

int main(void) {
    int s, k;
    long long int b = 1;
    scanf("%d %d", &s, &k);
    while (s != 0) {
        b *= s / k;
        s -= s / k;
        k -= 1;
    }
    printf("%lld", b);
}