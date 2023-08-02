#include<stdio.h>

int main() {
    int n, dp[51] = {1, 1};
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
    }
    printf("%d", dp[n]);
}