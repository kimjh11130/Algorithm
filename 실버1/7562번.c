#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int main(void) {
    int k, dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int n, arr[301][301] = {0}, r = -1, f = -1, a, b, x1, y1;
        element que[90000];
        scanf("%d", &n);
        scanf("%d %d %d %d", &a, &b, &x1, &y1);
        que[++r].x = a, que[r].y = b;
        arr[a][b] = 1;
        while (f < r) {
            int x = que[++f].x, y = que[f].y;
            if (x == x1 && y == y1) {
                printf("%d\n", arr[x][y] - 1);
                break;
            }
            for (int j = 0; j < 8; j++) {
                int nx = x + dx[j], ny = y + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !arr[nx][ny]){
                    que[++r].x = nx, que[r].y = ny;
                    arr[nx][ny] = arr[x][y] + 1;
                }
            }
        }
    }
}