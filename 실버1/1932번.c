#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, arr[501][501] = {0}, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &arr[i][j]);
            arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
            r = max(r, arr[i][j]);
        }
    }
    printf("%d", r);
}