#include <stdio.h>

typedef struct element {
    int x, y, c;
    char item;
} element;

int main() {
    int a, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        int n, m, r = 0, f = -1, q = 1;
        char arr[1001][1001];
        element que[5000001];
        scanf("%d %d", &m, &n);
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                scanf(" %1c", &arr[j][k]);
                if (arr[j][k] == '*') {
                    que[++r].x = j, que[r].y = k, que[r].c = 1;
                    que[r].item = arr[j][k];
                } else if (arr[j][k] == '@') {
                    que[0].x = j, que[0].y = k, que[0].c = 1;
                    que[0].item = arr[j][k];
                }
            }
        }
        while (f < r) {
            int x = que[++f].x, y = que[f].y, c = que[f].c;
            char item = que[f].item;
            if ((x == 1 || y == 1 || x == n || y == m) && arr[x][y] == '@') {
                printf("%d\n", c);
                q = 0;
                break;
            }
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j], ny = y + dy[j];
                if (item == '@' && arr[x][y] == '@' && arr[nx][ny] == '.') {
                    arr[nx][ny] = '@';
                    que[++r].x = nx, que[r].y = ny, que[r].c = c + 1;
                    que[r].item = item;
                }
                if (item == '*' && (arr[nx][ny] == '.' || arr[nx][ny] == '@')) {
                    arr[nx][ny] = '*';
                    que[++r].x = nx, que[r].y = ny, que[r].c = c + 1;
                    que[r].item = item;
                }
            }
        }
        if (q) printf("IMPOSSIBLE\n");
    }
}