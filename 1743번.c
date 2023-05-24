#include <stdio.h>

int n, m, arr[101][101] = {0};
typedef struct element {
    int x;
    int y;
} element;
element que[10000];

int bfs(int x1, int y1) {
    int cnt = 0, r = 0, f = 0;
    que[++r].x = x1;
    que[r].y = y1;
    while (f < r) {
        int x = que[++f].x;
        int y = que[f].y;
        if (x >= 1 && x <= n && y >= 1 && y <= m) {
            cnt++;
            if (arr[x + 1][y]) {
                arr[x + 1][y] = 0;
                que[++r].x = x + 1;
                que[r].y = y;
            }
            if (arr[x][y + 1]) {
                arr[x][y + 1] = 0;
                que[++r].x = x;
                que[r].y = y + 1;
            }
            if (arr[x - 1][y]) {
                arr[x - 1][y] = 0;
                que[++r].x = x - 1;
                que[r].y = y;
            }
            if (arr[x][y - 1]) {
                arr[x][y - 1] = 0;
                que[++r].x = x;
                que[r].y = y - 1;
            }
        }
    }
    return cnt - 1;
}

int main() {
    int k, x, y, max = 0, comp;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        arr[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j]) {
                comp = bfs(i, j);
                if (comp > max) max = comp;
            }
        }
    }
    printf("%d", max);
}