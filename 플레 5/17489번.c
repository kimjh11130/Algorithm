#include <stdio.h>

int n, m, l, flag, a, b, max, d[] = {0, -1, 0, 1};
char str[27], arr[101][101], vis[101][101];

void back(int x, int y, int c) {
    if (flag) return;
    if (c % l == 0 && c / l > max) {
        if (vis[x][y] > 1) flag = 1;
        else max = c / l, a = x + 1, b = y + 1;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == str[c % l]) {
            vis[nx][ny] += 1, back(nx, ny, c + 1), vis[nx][ny] -= 1;
        }
    }
}

int main(void) {
    scanf("%d %d %d", &n, &m, &l);
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    if (arr[0][0] == str[0]) vis[0][0] = 1,back(0, 0, 1);
    if (!(a + b + max) || flag) printf("-1");
    else printf("%d\n%d %d", max, a, b);
}