#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int n, r = -1, f = -1, cnt = 0, d[] = {-1, 0, 1}, dx, dy;
char arr[2002][2002];
element que[40022002];

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == 'F') que[++r].x = i, que[r].y = j;
        }
    }
    while (f < r) {
        int x = que[++f].x, y = que[f].y;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                dx = x + d[i], dy = y + d[j];
                if (i == 2 && j == 1) continue;
                if (arr[dx][dy] == '.') {
                    que[++r].x = dx, que[r].y = dy;
                    cnt++, arr[dx][dy] = '#';
                }
            }
        }
    }
    printf("%d", cnt);
}
