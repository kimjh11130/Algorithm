#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int n, m, dp[1001][1001], max = 0;
    char arr[1001][1001];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        for (int j = 0; j < m; j++) {
            if (!i || !j) dp[i][j] = arr[i][j] == 48 ? 0 : 1;
            else if (arr[i][j] == 49) dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            else dp[i][j] = 0;
            max = dp[i][j] * dp[i][j] > max ? dp[i][j] * dp[i][j] : max;
        }
    }
    printf("%d", max);
}