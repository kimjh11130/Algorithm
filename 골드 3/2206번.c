#include <stdio.h>

typedef struct element {
    int x, y, z, c;
} element;

int n, m, r = -1, f = -1;
short arr[1001][1001], vis[1001][1001][2], d[] = {0, -1, 0, 1};
element que[2000000];

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    que[++r].x = 0, que[r].y = 0, que[r].z = 0, que[r].c = 1, vis[0][0][0] = 1;
    while (f < r) {
        int x = que[++f].x, y = que[f].y, z = que[f].z, c = que[f].c;
        if (x == n - 1 && y == m - 1) {
            printf("%d", c);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny][z]) {
                if (!arr[nx][ny]) que[++r].x = nx, que[r].y = ny, que[r].z = z, que[r].c = c + 1, vis[nx][ny][z] = 1;
                else if (!z)que[++r].x = nx, que[r].y = ny, que[r].z = 1, que[r].c = c + 1, vis[nx][ny][1] = 1;
            }
        }
    }
    printf("-1");
}