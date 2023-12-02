#include <stdio.h>

typedef struct element {
    int x, y, c, t;
} element;

int main(void) {
    int n, k, r = -1, f = -1, arr[202][202] = {0}, s, X, Y, d[] = {0, -1, 0, 1};
    element que[400000];
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= n; l++) {
                if (arr[j][l] == i) que[++r].x = j, que[r].y = l, que[r].c = i, que[r].t = 0;
            }
        }
    }
    scanf("%d %d %d", &s, &X, &Y);
    while (f < r) {
        int x = que[++f].x, y = que[f].y, c = que[f].c, t = que[f].t;
        if (s <= t) {
            printf("%d", arr[X][Y]);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            if (nx <= n && ny <= n && nx > 0 && ny > 0 && arr[nx][ny] == 0) {
                arr[nx][ny] = c;
                que[++r].x = nx, que[r].y = ny, que[r].c = c, que[r].t = t + 1;
            }
        }
    }
    printf("%d", arr[X][Y]);
}