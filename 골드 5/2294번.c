#include <stdio.h>

int main() {
    int n, k, arr[101] = {0}, dp[100001] = {0};
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]), dp[arr[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            if (dp[j - arr[i]] != 0) {
                if (dp[j] != 0) {
                    dp[j] = dp[j] > dp[j - arr[i]] + 1 ? dp[j - arr[i]] + 1 : dp[j];
                } else {
                    dp[j] += dp[j - arr[i]] + 1;
                }
            }
        }
    }
    printf("%d ", dp[k] ? dp[k] : -1);
}