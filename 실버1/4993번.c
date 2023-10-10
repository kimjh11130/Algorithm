#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int main(void) {
    while (1) {
        int n, m, r = -1, f = -1, cnt = 0, d[] = {0, -1, 0, 1};
        element que[400] = {0};
        char arr[22][22] = {0};
        scanf("%d %d", &m, &n);
        if (m + n == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf(" %1c", &arr[i][j]);
                if (arr[i][j] == '@') que[++r].x = i, que[r].y = j, cnt++;
            }
        }
        while (r > f) {
            int x = que[++f].x, y = que[f].y;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[3 - i];
                if (arr[nx][ny] == '.') {
                    arr[nx][ny] = '@', cnt++;
                    que[++r].x = nx, que[r].y = ny;
                }
            }
        }
        printf("%d\n", cnt);
    }
}