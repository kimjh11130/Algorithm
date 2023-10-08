#include <stdio.h>

int n, arr[102][102], max, a = 1, v[102][102], d[] = {0, -1, 0, 1};

void dfs(int x, int y, int t) {
    v[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int dx = x + d[i], dy = y + d[3 - i];
        if (arr[dx][dy] > t && v[dx][dy] == 0) dfs(dx, dy, t);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            max = max > arr[i][j] ? max : arr[i][j];
        }
    }
    for (int t = 1; t < max; t++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                v[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > t && v[i][j] == 0) {
                    dfs(i, j, t);
                    cnt++;
                }
            }
        }
        a = a > cnt ? a : cnt;
    }
    printf("%d", a);
}