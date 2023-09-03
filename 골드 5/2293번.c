#include <stdio.h>

int main() {
    int n, k, arr[101] = {0}, dp[10001] = {1};
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; ++j) {
            dp[j] += dp[j - arr[i]];
        }
    }
    printf("%d", dp[k]);
}