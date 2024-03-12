#include <stdio.h>

#define INF 987654321

typedef struct element {
    int x, y, c;
} element;

int main() {
    int n, m, vis[101][101], r = 0, f = -1;
    char arr[101][101], d[] = {0, -1, 0, 1};
    element que[2000000];
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) scanf("%s", arr[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = INF;
        }
    }
    que[r].x = 0, que[r].y = 0, que[r].c = 0;
    while (f < r) {
        int x = que[++f].x, y = que[f].y, c = que[f].c;
        if (x == n - 1 && y == m - 1) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i], tmp;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                tmp = c + arr[nx][ny] - 48;
                if (tmp < vis[nx][ny]) {
                    que[++r].x = nx, que[r].y = ny, que[r].c = tmp, vis[nx][ny] = tmp;
                }
            }
        }
    }
    printf("%d", n + m == 2 ? 0 : vis[n - 1][m - 1]);
}