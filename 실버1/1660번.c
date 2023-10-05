#include <stdio.h>

int main() {
    int n, dp[300001] = {0}, arr[1000] = {0};
    scanf("%d", &n);
    for (int i = 1; arr[i - 1] <= n; i++) arr[i] = arr[i - 1] + i;
    for (int i = 1; arr[i - 1] <= n; i++) arr[i] += arr[i - 1];
    for (int i = 1; i <= n; i++) {
        int min = 1000000;
        for (int j = 1; arr[j] <= i; j++) {
            min = min > dp[i - arr[j]] ? dp[i - arr[j]] : min;
        }
        dp[i] = min + 1;
    }
    printf("%d \n", dp[n]);
}
