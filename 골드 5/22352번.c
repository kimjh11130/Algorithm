#include <stdio.h>

int n, m, arr[32][32], arr1[32][32], nx, ny, a;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int dfs(int x, int y, int c, int z) {
    arr[x][y] = z;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i], ny = y + dy[i];
        if (arr[nx][ny] == c) {
            dfs(nx, ny, c, z);
        }
    }
    return 0;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (!i) scanf("%d", &arr[j][k]);
                else scanf("%d", &arr1[j][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] != arr1[i][j] && !a) {
                dfs(i, j, arr[i][j], arr1[i][j]), a++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] != arr1[i][j]) {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
}