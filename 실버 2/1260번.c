#include <stdio.h>

int n, arr[1001][1001], visit[1001], que[1000000], r = -1, f = -1;

void dfs(int x) {
    printf("%d ", x);
    for (int i = 1; i <= n; i++) {
        if (arr[i][x] == 1 && !visit[i]) {
            visit[i] = 1;
            dfs(i);
        }
    }
}

void bfs(int x1) {
    que[++r] = x1;
    while (f < r) {
        int x = que[++f];
        printf("%d ", x);
        for (int i = 1; i <= n; i++) {
            if (arr[i][x] == 1 && !visit[i]) {
                visit[i] = 1;
                que[++r] = i;
            }
        }
    }
}

int main(void) {
    int m, v, x, y;
    scanf("%d %d %d", &n, &m, &v);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        arr[x][y] = 1, arr[y][x] = 1;
    }
    visit[v] = 1;
    dfs(v);
    printf("\n");
    for (int i = 1; i <= n; i++) {
        visit[i] = 0;
    }
    visit[v] = 1;
    bfs(v);
}