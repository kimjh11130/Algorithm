#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, arr[1001], dp[1001] = {0}, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]), dp[i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[i]) dp[j] = max(dp[i] + arr[j], dp[j]);
        }
        res = max(res, dp[i]);
    }
    printf("%d", res);
}