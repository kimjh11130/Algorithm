#include <stdio.h>

int twojin(short *arr, int num) {
    int i = 0;
    while (num) {
        arr[i++] = num % 2, num /= 2;
    }
    return i;
}

int main(void) {
    int x, k, xi = 0, ki = 0, a = 0, i;
    short xto[70] = {0}, kto[32] = {0};
    long long int res = 0, two = 1;
    scanf("%d %d", &x, &k);
    twojin(xto, x), i = twojin(kto, k);
    while (i != ki) {
        if (!xto[xi]) res += kto[ki++] * two;
        a++, xi++, two *= 2;
    }
    printf("%lld", res);
}
