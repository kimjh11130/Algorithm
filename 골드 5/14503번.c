#include <stdio.h>

int n, m, sw[] = {0, 3, 2, 1};
short arr[50][50] = {0}, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int check(int x, int y, int aa) {
    if (x > 0 && y > 0 && x < n - 1 && y < m - 1) {
        if (aa) return arr[x][y] == 0;
        return arr[x][y] != 1;
    }
    return 0;
}


int main() {
    int x, y, d, cnt = 0;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    d = sw[d];
    while (1) {
        int flag = 0, rev = (d + 2) % 4;
        if (!arr[x][y]) arr[x][y] = 2, cnt++;
        for (int i = 0; i < 4; i++) {
            if (check(x + dx[i], y + dy[i], 1)) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            d = (d + 1) % 4;
            if (check(x + dx[d], y + dy[d], 1)) x += dx[d], y += dy[d];
        } else {
            if (check(x + dx[rev], y + dy[rev], 0)) x += dx[rev], y += dy[rev];
            else {
                printf("%d", cnt);
                return 0;
            }
        }
    }

}
