#include <stdio.h>

int main() {
    int n, dp[10] = {1}, tmp[10] = {0}, res = 0, mod = 10007;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                tmp[k] = (tmp[k] + dp[j]) % mod;
            }
            if (i == n - 1) res = (res + tmp[j]) % mod;
        }
        for (int j = 0; j < 10; j++) {
            dp[j] = tmp[j], tmp[j] = 0;
        }
    }
    printf("%d", res);
}