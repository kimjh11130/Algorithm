#include <stdio.h>

int n, m, cnt;
char arr[51][51];

void dfs(int x, int y, char c) {
    if (c == '-' && arr[x][y + 1] == c && y + 1 < m) dfs(x, y + 1, c);
    else if (c == '|' && arr[x + 1][y] == c && x + 1 < n) dfs(x + 1, y, c);
    arr[x][y] = '.';
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", arr[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != '.') dfs(i, j, arr[i][j]), cnt++;
        }
    }
    printf("%d", cnt);
}
