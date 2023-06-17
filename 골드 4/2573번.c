#include <stdio.h>

int arr[301][301] = {0}, visited[301][301] = {0}, n, m;
struct element {
    int x;
    int y;
    int zero;
};
struct element que[10001] = {0};

int bfs(int x1, int y1) {
    int r = -1, f = -1;
    que[++r].x = x1;
    que[r].y = y1;
    que[r].zero = 0;
    visited[x1][y1] = 1;
    while (f < r) {
        int x = que[++f].x;
        int y = que[f].y;
        if (!arr[x - 1][y])que[f].zero++;
        else if (!visited[x - 1][y] && arr[x - 1][y]) {
            que[++r].x = x - 1;
            que[r].y = y;
            que[r].zero = 0;
            visited[x - 1][y] = 1;
        }
        if (!arr[x + 1][y])que[f].zero++;
        else if (!visited[x + 1][y] && arr[x + 1][y]) {
            que[++r].x = x + 1;
            que[r].y = y;
            que[r].zero = 0;
            visited[x + 1][y] = 1;
        }
        if (!arr[x][y - 1])que[f].zero++;
        else if (!visited[x][y - 1] && arr[x][y - 1]) {
            que[++r].x = x;
            que[r].y = y - 1;
            que[r].zero = 0;
            visited[x][y - 1] = 1;
        }
        if (!arr[x][y + 1])que[f].zero++;
        else if (!visited[x][y + 1] && arr[x][y + 1]) {
            que[++r].x = x;
            que[r].y = y + 1;
            que[r].zero = 0;
            visited[x][y + 1] = 1;
        }
    }
    for (int i = 0; i <= r; i++) {
        arr[que[i].x][que[i].y] -= arr[que[i].x][que[i].y] > que[i].zero ? que[i].zero : arr[que[i].x][que[i].y];
    }
    return 0;
}

int main(void) {
    int cnt = 0, result = -1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while (cnt < 2) {
        cnt = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                visited[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        if(!cnt){
            printf("0");
            return 0;
        }
        result++;
    }
    printf("%d", result);
}