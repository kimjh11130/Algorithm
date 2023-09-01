#include <stdio.h>

typedef struct element {
    int x, y, d;
} element;

int main() {
    int n, d, dp[10000] = {0};
    element arr[12];
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].d);
    }
    for (int i = 1; i <= d; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < n; j++) {
            if (arr[j].y == i && dp[i] > dp[arr[j].x] + arr[j].d){
                dp[i] = dp[arr[j].x] + arr[j].d;
            }
        }
    }
    printf("%d", dp[d]);
}

