#include <stdio.h>

int main(void) {
    int n, arr[10][101] = {0}, cnt = 0, mod = 1e9;
    scanf("%d", &n);
    for (int i = 1; i < 10; i++) arr[i][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j > 0) arr[j][i] = (arr[j][i] + arr[j - 1][i - 1]) % mod;
            if (j < 9) arr[j][i] = (arr[j][i] + arr[j + 1][i - 1]) % mod;
        }
    }
    for (int i = 0; i < 10; i++) {
        cnt = (cnt + arr[i][n - 1]) % mod;
    }
    printf("%d", cnt);
}