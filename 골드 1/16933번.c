#include <stdio.h>

typedef struct element {
    int x, y, z, c, flag;
} element;

char arr[1001][1001], vis[1001][1001][11];
element que[20050000];

int main(void) {
    int n, m, k, r = 0, f = -1, d[] = {0, 1, 0, -1};
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    que[r].x = 0, que[r].y = 0, que[r].z = 0, que[r].c = 1, que[r].flag = 1, vis[0][0][0] = 1;
    while (f <= r) {
        int x = que[++f].x, y = que[f].y, z = que[f].z, c = que[f].c, flag = que[f].flag;
        if (x == n - 1 && y == m - 1) {
            printf("%d", c);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (arr[nx][ny] == 48 && !vis[nx][ny][z]) {
                    que[++r].x = nx, que[r].y = ny, que[r].z = z, que[r].c =
                            c + 1, que[r].flag = !flag, vis[nx][ny][z] = 1;
                } else if (arr[nx][ny] == 49 && !vis[nx][ny][z + 1] && z < k) {
                    if (flag) que[++r].x = nx, que[r].y = ny, que[r].z = z + 1, vis[nx][ny][z + 1] = 1;
                    else que[++r].x = x, que[r].y = y, que[r].z = z;
                    que[r].c = c + 1, que[r].flag = !flag;
                }
            }
        }
    }
    printf("-1");
}