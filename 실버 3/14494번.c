#include <stdio.h>

int main(void) {
    int n, m, a = 1e9 + 7;
    long long int dp[1002][1002] = {1};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % a;
        }
    }
    printf("%lld", dp[n][m]);
}