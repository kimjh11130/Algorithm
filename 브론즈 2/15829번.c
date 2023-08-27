#include <stdio.h>

int main(void) {
    int n, m = 1234567891;
    long long int a = 0, s = 1;
    char arr[50] = {0};
    scanf("%d\n%s", &n, arr);
    for (int i = 0; i < n; ++i) {
        a += (arr[i] - 96) * s, s *= 31;
        s %= m, a %= m;
    }
    printf("%lld", a);
}