#include <stdio.h>

int min(int a, int b) {
    return !a || a > b ? b : a;
}

int main(void) {
    int n, arr[710] = {1,}, dp[1000001] = {0};
    scanf("%d", &n);
    for (int i = 1; arr[i - 1] < 1000001; i++) {
        arr[i] = arr[i - 1] + 4 * i + 1;
        for (int j = arr[i - 1]; j < 1000001; j++) {
            dp[j] = min(dp[j], dp[j - arr[i - 1]] + 1);
        }
    }
    printf("%d", dp[n]);
}
