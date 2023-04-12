#include "stdio.h"

int memo[51][51] = {0};

int dfs(int x, int y) {
    if (x == -1 || y == -1 || memo[x][y] == 0) {
        return 0;
    }
    memo[x][y] = 0;

    dfs(x + 1, y + 1);
    dfs(x, y + 1);
    dfs(x - 1, y + 1);
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x + 1, y - 1);
    dfs(x, y - 1);
    dfs(x - 1, y - 1);
    return 1;
}

int main(void) {
    while (1) {
        int x, y, result = 0;
        scanf("%d %d", &y, &x);
        if (!x && !y) break;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                scanf("%d", &memo[i][j]);
            }
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (memo[i][j] == 1) {
                    dfs(i, j);
                    result++;
                }
            }
        }
        printf("%d\n", result);
    }
}