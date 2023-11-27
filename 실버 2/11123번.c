#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int bfs(int i, int j, char arr[][102]) {
    int r = -1, f = -1, d[] = {0, -1, 0, 1};
    element que[100002];
    que[++r].x = i, que[r].y = j;
    while (f < r) {
        int x = que[++f].x, y = que[f].y;
        for (int k = 0; k < 4; k++) {
            int dx = x + d[k], dy = y + d[3 - k];
            if (arr[dx][dy] == '#') {
                que[++r].x = dx, que[r].y = dy;
                arr[dx][dy] = '.';
            }
        }
    }
    return 0;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int h, w, cnt = 0;
        char arr[102][102] = {0};
        scanf("%d %d", &h, &w);
        for (int j = 1; j <= h; j++) {
            for (int k = 1; k <= w; k++) {
                scanf(" %1c", &arr[j][k]);
            }
        }
        for (int j = 1; j <= h; j++) {
            for (int k = 1; k <= w; k++) {
                if (arr[j][k] == '#') {
                    arr[j][k] = '.';
                    cnt++, bfs(j, k, arr);
                }
            }
        }
        printf("%d\n", cnt);
    }
}