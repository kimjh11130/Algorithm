#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int main(void) {
    int n, m, r = -1, f = -1, cnt = 0, d[] = {0, 1, 0, -1};
    element que[360000];
    char arr[602][602] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == 'I') que[++r].x = i, que[r].y = j;
        }
    }
    while (r > f) {
        int x = que[++f].x, y = que[f].y;
        for (int i = 0; i < 4; i++) {
            int dx = x + d[i], dy = y + d[3 - i];
            if (arr[dx][dy] == 'P') que[++r].x = dx, que[r].y = dy, cnt++;
            else if (arr[dx][dy] == 'O')que[++r].x = dx, que[r].y = dy;
            arr[dx][dy] = 'X';
        }
    }
    if (cnt == 0) printf("TT");
    else printf("%d", cnt);
}