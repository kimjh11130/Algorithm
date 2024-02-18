#include <stdio.h>

typedef struct element {
    int x, y, c;
} element;

int main(void) {
    int n, r = -1, f = -1, all = 0;
    char arr[4][53] = {0}, vis[4][53] = {0};
    element que[101];
    scanf("%d", &n);
    for (int i = 1; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == '.') all++;
        }
    }
    if (arr[1][1] == '.')que[++r].x = 1, que[r].y = 1, que[r].c = 1, vis[1][1] = 1;;
    if (arr[2][1] == '.')que[++r].x = 2, que[r].y = 1, que[r].c = 1, vis[2][1] = 1;;
    while (f < r) {
        int x = que[++f].x, y = que[f].y, c = que[f].c;
        if (y == n) {
            printf("%d", all - c);
            return 0;
        }
        for (int i = -1; i < 2; i++) {
            int nx = x + i, ny = y + (i == 0 ? 1 : 0);
            if (arr[nx][ny] == '.' && !vis[nx][ny]) {
                que[++r].x = nx, que[r].y = ny, que[r].c = c + 1;
                vis[nx][ny] = 1;
            }
        }
    }

}