#include <stdio.h>

int main(void) {
    long long int n, arr[1515] = {0, 1}, mod = 1e9 + 7;
    scanf("%lld", &n);
    for (int i = 2; i < n; i++) {
        arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % mod;
    }
    printf("%lld", arr[n - 1]);
}