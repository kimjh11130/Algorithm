#include <stdio.h>

typedef struct element {
    int x, y, c;
} element;

void reset(int n, int arr[][126]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
}

int main() {
    int n, d[] = {0, -1, 0, 1}, cnt = 1, arr[126][126], vis[126][126], r, f, tmp;
    element que[4000000];
    scanf("%d", &n);
    while (n) {
        r = 0, f = -1, reset(n, arr), reset(n, vis);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        que[r].x = 0, que[r].y = 0, que[r].c = arr[0][0], vis[0][0] = arr[0][0];
        while (f < r) {
            int x = que[++f].x, y = que[f].y, c = que[f].c;
            if (x == n - 1 && y == n - 1) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[3 - i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    tmp = arr[nx][ny] + c;
                    if (tmp < vis[nx][ny] || !vis[nx][ny]) {
                        que[++r].x = nx, que[r].y = ny, que[r].c = tmp;
                        vis[nx][ny] = tmp ? tmp : -1;
                    }
                }
            }
        }
        printf("Problem %d: %d\n", cnt++, vis[n - 1][n - 1] + 1 ? vis[n - 1][n - 1] : 0);
        scanf("%d", &n);
    }
}