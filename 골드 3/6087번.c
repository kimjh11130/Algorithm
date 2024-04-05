#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int main() {
    int n, m, a = 1, d[] = {0, 1, 0, -1}, r = 0, f = -1, vis[101][101] = {0};
    char arr[101][101];
    element que[10001];
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) scanf("%s", arr[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a && arr[i][j] == 'C') arr[i][j] = '*', que[r].x = i, que[r].y = j, a = 0;
        }
    }
    while (f < r) {
        int x = que[++f].x, y = que[f].y, c = vis[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            while (0 <= nx && nx < n && 0 <= ny && ny < m) {
                char cur = arr[nx][ny];
                if (cur == '*') break;
                else if (cur == 'C') {
                    printf("%d", c);
                    return 0;
                } else if (!vis[nx][ny]) vis[nx][ny] = c + 1, que[++r].x = nx, que[r].y = ny;
                nx += d[i], ny += d[3 - i];
            }
        }
    }
}
