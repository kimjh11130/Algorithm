#include <stdio.h>

int main(void) {
    int n, i;
    char arr[1000001] = {0};
    long long int res = 1, a;
    scanf("%d", &n);
    for (i = 2; i * i <= n; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= n; j += i) {
                arr[j] = 1;
            }
        }
    }
    for (i = 2; i <= n; i++) {
        if (!arr[i]) {
            a = i;
            while (a * i <= n) a *= i;
            res = res * a % 987654321;
        }
    }
    printf("%lld", res);
}