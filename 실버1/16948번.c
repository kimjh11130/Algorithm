#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int main(void) {
    int n, r1, c1, r2, c2, r = 0, f = 0, arr[202][202] = {0};
    int dx[] = {-2, -2, 0, 0, 2, 2}, dy[] = {-1, 1, -2, 2, -1, 1};
    element que[50000];
    scanf("%d", &n);
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    arr[r1][c1] = 1;
    que[++r].x = r1, que[r].y = c1;
    while (f < r) {
        int x = que[++f].x, y = que[f].y;
        if (x == r2 && y == c2) {
            printf("%d", arr[x][y] - 1);
            return 0;
        }
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !arr[nx][ny]) {
                que[++r].x = nx, que[r].y = ny;
                arr[nx][ny] = arr[x][y] + 1;
            }
        }
    }
    printf("-1");
}