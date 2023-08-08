#include <stdio.h>

int main(void) {
    int a, weight[21] = {0}, value[23] = {0}, dp[22][100] = {0};
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 1; i <= a; i++) {
        scanf("%d", &value[i]);
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j < 100; j++) {
            if (weight[i] <= j) {
                if (dp[i - 1][j] > dp[i - 1][j - weight[i]] + value[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - weight[i]] + value[i];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d", dp[a][99]);
}