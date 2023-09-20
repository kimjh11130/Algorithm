#include <stdio.h>

int n, m, g, a = 0, b = 0, d[4] = {0, -1, 0, 1};
char arr[102][102] = {0}, f;

void dfs(int x, int y, char c) {
    g += 1, arr[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int dx = x + d[i], dy = y + d[3 - i];
        if (arr[dx][dy] == c) dfs(dx, dy, c);
    }
}

int main(void) {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g = 0, f = arr[i][j];
            if (f != 0) {
                dfs(i, j, f);
                if (f == 'W')a += g * g;
                else b += g * g;
            }
        }
    }
    printf("%d %d", a, b);
}
