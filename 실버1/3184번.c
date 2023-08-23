#include <stdio.h>

int v, o, d[4] = {-1, 0, 1, 0};
char arr[252][252];

void bfs(int x1, int y1) {
    struct element {
        int x, y;
    };
    int r = -1, f = -1, s = arr[x1][y1] == 'o' ? 1 : 0, w = arr[x1][y1] == 'v' ? 1 : 0;
    struct element que[62500] = {0};
    que[++r].x = x1, que[r].y = y1;
    while (r > f) {
        int x = que[++f].x, y = que[f].y;
        arr[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            char c = arr[x + d[i]][y + d[3 - i]];
            if (c != '#' && c != 0) {
                que[++r].x = x + d[i], que[r].y = y + d[3 - i];
                if (c == 'v') w++;
                else if (c == 'o')s++;
                arr[x + d[i]][y + d[3 - i]] = '#';
            }
        }
    }
    if (s > w) o += s;
    else v += w;
}

int main(void) {
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (arr[i][j] != '#') bfs(i, j);
        }
    }
    printf("%d %d", o, v);
}