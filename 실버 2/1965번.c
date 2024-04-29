#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, arr[1001], dp[1001], res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]), dp[i] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if(arr[j] > arr[i]) dp[j] = max(dp[j], dp[i] + 1);
        }
        res = max(res, dp[i]);
    }
    printf("%d", res);
}