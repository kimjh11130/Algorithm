#include <stdio.h>

int main(void) {
    int n, m, dp[10001] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) dp[i] = i >= m ? (dp[i - m] + dp[i - 1]) % 1000000007 : 1;
    printf("%d", dp[n]);
}