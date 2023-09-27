#include <stdio.h>

int main(void) {
    int n, m, mod = 1e9+9;
    long long int arr[1000001] = {0, 1, 2, 4};
    scanf("%d", &n);
    for (int i = 4; i <= 1000000; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % mod;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        printf("%lld\n", arr[m]);
    }
}