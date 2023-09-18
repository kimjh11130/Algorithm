#include <stdio.h>

int main(void) {
    int d, k, dp[31] = {0, 1}, c;
    scanf("%d %d", &d, &k);
    for (int i = 2; i < d; i++) dp[i] = dp[i - 1] + dp[i - 2];
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            c = i * dp[d - 2] + j * dp[d - 1];
            if (c == k) {
                printf("%d\n%d", i, j);
                return 0;
            } else if (c > k)break;
        }
    }
}
