#include <stdio.h>

int n, m, k, res, d[] = {0, -1, 0, 1};
char arr[5][5];

void back(int x, int y, int cnt) {
    if (cnt == k && !x && y == m - 1) res++;
    else if (cnt > k || (!x && y == m - 1)) return;
    else {
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == '.') {
                arr[nx][ny] = 'T', back(nx, ny, cnt + 1), arr[nx][ny] = '.';
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    arr[n - 1][0] = 'T', back(n - 1, 0, 1);
    printf("%d", res);
}