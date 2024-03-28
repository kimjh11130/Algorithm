#include <stdio.h>

int main() {
    int n, stack[80001] = {0}, a, t = 0;
    long long int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        while (t && a >= stack[t - 1]) --t, stack[t] = 0;
        stack[t] = a, cnt += t++;
    }
    printf("%lld", cnt);
}
