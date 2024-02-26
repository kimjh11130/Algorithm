#include <stdio.h>

typedef struct element {
    int x, y, z, c;
} element;

int main() {
    int n, m, k, r = 0, f = -1, d[] = {0, -1, 0, 1};
    char arr[1001][1001] = {0}, vis[1001][1001][11] = {0};
    element que[20000000];
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    que[r].x = 0, que[r].y = 0, que[r].z = 0, que[r].c = 1;
    while (f < r) {
        int x = que[++f].x, y = que[f].y, z = que[f].z, c = que[f].c;
        if (x == n - 1 && y == m - 1) {
            printf("%d", c);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (arr[nx][ny] == 49) {
                    if (z < k && !vis[nx][ny][z + 1]) {
                        que[++r].x = nx, que[r].y = ny, que[r].z = z + 1, que[r].c = c + 1, vis[nx][ny][z + 1] = 1;
                    }
                } else if (!vis[nx][ny][z]) {
                    que[++r].x = nx, que[r].y = ny, que[r].z = z, que[r].c = c + 1, vis[nx][ny][z] = 1;
                }
            }
        }
    }
    printf("-1");
}