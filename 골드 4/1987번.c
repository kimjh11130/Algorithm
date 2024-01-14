#include <stdio.h>

int n, m, max;
char arr[22][22], vis[28], d[] = {1, 0, -1, 0};

void back(int x, int y, int a) {
    if (a > max) max = a;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (nx < n && ny < m && nx >= 0 && ny >= 0 && !vis[arr[nx][ny] - 65]) {
            vis[arr[nx][ny] - 65] = 1;
            back(nx, ny, a + 1);
            vis[arr[nx][ny] - 65] = 0;
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    vis[arr[0][0] - 65] = 1;
    back(0, 0, 1);
    printf("%d", max);
}