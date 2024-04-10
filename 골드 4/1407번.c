#include <stdio.h>

int main() {
    long long int a, b, t = 2, cnt = 0;
    scanf("%lld %lld", &a, &b), a -= 1;
    while (b >= t) cnt += (b / t - a / t) * t / 2, t *= 2;
    printf("%lld", cnt + b - a);
}
