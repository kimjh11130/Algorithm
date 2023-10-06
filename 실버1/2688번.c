#include <stdio.h>

int main(void) {
    int t, n;
    long long int dp[11][65] = {0};
    for (int i = 0; i < 10; i++) dp[i][0] = 1;
    for (int i = 1; i < 65; i++) {
        for (int j = 9; j >= 0; j--) {
            dp[j][i] += dp[j+1][i] + dp[j][i-1];
        }
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", dp[0][n]);
    }
}
