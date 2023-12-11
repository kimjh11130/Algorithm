#include <stdio.h>

typedef struct element {
    int x, y, t;
    char c;
} element;

int main(void) {
    int R, C, f = -1, r = -1, d[] = {0, 1, 0, -1};
    char arr[52][52] = {0};
    element que[5022];
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == '*') {
                que[++r].x = i, que[r].y = j, que[r].c = '*', que[r].t = 0;
            }
        }
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (arr[i][j] == 'S') {
                que[++r].x = i, que[r].y = j, que[r].c = 'S', que[r].t = 0;
            }
        }
    }
    while (f < r) {
        int x = que[++f].x, y = que[f].y, t = que[f].t;
        char c = que[f].c;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            if (arr[nx][ny] == '.' || arr[nx][ny] == 'S' && c == '*') {
                arr[nx][ny] = c;
                que[++r].x = nx, que[r].y = ny, que[r].c = c, que[r].t = t + 1;
            } else if (arr[nx][ny] == 'D' && c == 'S') {
                printf("%d", t + 1);
                return 0;
            }
        }
    }
    printf("KAKTUS");
}