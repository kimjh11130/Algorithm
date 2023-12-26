#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int main(void) {
    int a, b, c, d = 0, e = 0, n, r = -1, f = -1, cnt = 0, arr[101][101] = {0}, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1,0};
    element bam[10001], change[101];
    scanf("%d %d", &n, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 2;
    }
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d %c", &change[i].x, &change[i].y);
    }
    bam[++r].x = 1, bam[r].y = 1, arr[1][1] = 1;
    while (f < r) {
        int x = bam[r].x, y = bam[r].y, ex = bam[++f].x, ey = bam[f].y;
        if (change[e].x == cnt) {
            if (change[e].y == 'L') d = (4 + d - 1) % 4;
            else if (change[e].y == 'D') d = (4 + d + 1) % 4;
            e++;
        }

        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 1 || ny < 1 || nx > n || ny > n || arr[nx][ny] == 1) {
            printf("%d", cnt + 1);
            return 0;
        }
        arr[ex][ey] = 0;
        if (arr[nx][ny] == 2) f--, arr[ex][ey] = 1;
        bam[++r].x = nx, bam[r].y = ny, arr[nx][ny] = 1, cnt++;
    }
}