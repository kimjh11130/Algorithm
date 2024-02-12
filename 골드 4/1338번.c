#include <stdio.h>

int main(void) {
    long long int f, l, x, y, tmp;
    scanf("%lld %lld %lld %lld", &f, &l, &x, &y);
    if (f > l) tmp = l, l = f, f = tmp;
    x = x > 0 ? x : -x, tmp = l / x * x + y;
    while (tmp > l) tmp -= x;
    if (y >= x || y < 0 || tmp < f || tmp - x >= f) {
        printf("Unknwon Number");
    } else {
        printf("%lld", tmp);
    }
}