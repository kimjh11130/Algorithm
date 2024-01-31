#include <stdio.h>

int main() {
    int n, arr[1001] = {0}, dp[1001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        dp[i] = 999;
    }
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j > 0; j--) {
            if (i + j < n) dp[i + j] = dp[i] + 1 > dp[i + j] ? dp[i + j] : dp[i] + 1;
        }
    }
    printf("%d", dp[n - 1] != 999 ? dp[n - 1] : -1);
}