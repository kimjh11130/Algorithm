#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int factorial(int n, int k) {
    int dp[401][201] = {0};
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || i == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % (int) 1e9;
        }
    }
    return dp[n][k];
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", factorial(n + k - 1, k - 1 > n ? n : k - 1));
}