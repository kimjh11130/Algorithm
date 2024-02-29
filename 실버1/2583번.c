#include <stdio.h>
#include <stdlib.h>

int m, n, cnt, d[] = {0, 1, 0, -1};
short vis[101][101];

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void dfs(int x, int y) {
    vis[x][y] = 1, cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny]) {
            vis[nx][ny] = 1, dfs(nx, ny);
        }
    }
}

int main() {
    int x1, y1, x2, y2, k, a = 0, arr[200] = {0};
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = y1; j < y2; j++) {
            for (int l = x1; l < x2; l++) {
                vis[j][l] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) dfs(i, j), arr[a++] = cnt, cnt = 0;
        }
    }
    qsort(arr, a, 4, comp);
    printf("%d\n", a);
    for (int i = 0; i < a; i++) {
        printf("%d ", arr[i]);
    }
}