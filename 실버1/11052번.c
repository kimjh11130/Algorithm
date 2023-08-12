#include <stdio.h>

int main(void) {
    int n, arr[1002] = {0}, dp[1002] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j++) {
            dp[j] = dp[j - i] + arr[i] > dp[j] ? dp[j - i] + arr[i] : dp[j];
        }
    }
    printf("%d", dp[n]);
}