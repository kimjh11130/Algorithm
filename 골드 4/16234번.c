#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int x, y;
} element;

int N, L, R, arr[52][52], result;

int max(int a, int b) {
    return a > b ? a : b;
}

int bfs(int i, int j, int vis[52][52]) {
    int r = -1, f = -1, cnt = 1, check[2502][2] = {0}, d[] = {0, -1, 0, 1}, all = 0;
    element que[2500];
    que[++r].x = i, que[r].y = j, vis[i][j] = 1;
    all += arr[i][j], check[cnt][0] = i, check[cnt][1] = j;
    while (f < r) {
        int x = que[++f].x, y = que[f].y;
        for (int k = 0; k < 4; k++) {
            int nx = x + d[k], ny = y + d[3 - k], btw = abs(arr[nx][ny] - arr[x][y]);
            if (L <= btw && btw <= R && nx > 0 && ny > 0 && nx <= N && ny <= N && vis[nx][ny] == 0) {
                que[++r].x = nx, que[r].y = ny, vis[nx][ny] = 1;
                check[++cnt][0] = nx, check[cnt][1] = ny, all += arr[nx][ny];
            }
        }
    }
    for (int k = 1; k <= cnt; k++) {
        arr[check[k][0]][check[k][1]] = all / cnt;
    }
    return cnt;
}

int main() {
    scanf("%d %d %d", &N, &L, &R);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while (result <= 2001) {
        int vis[52][52] = {0}, a = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (vis[i][j] == 0) a = max(a, bfs(i, j, vis));
            }
        }
        if (a == 1) {
            printf("%d", result);
            return 0;
        } else {
            result++;
        }
    }
}
