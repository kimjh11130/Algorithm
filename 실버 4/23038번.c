#include <stdio.h>

int main(void) {
    int n, m, d[] = {0, 2, 0, -2};
    char arr[901][901] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 3 * n; i++) {
        scanf("%s", arr[i]);
    }
    for (int i = 1; i < 3 * n; i += 3) {
        for (int j = 1; j < 3 * m; j += 3) {
            if (arr[i][j] == '.') {
                arr[i][j] = '#';
                for (int k = 0; k < 4; k++) {
                    int nx = i + d[k], ny = j + d[3 - k];
                    if (nx > 0 && ny > 0 && nx < 3 * n && ny < 3 * m && arr[nx][ny] == '#') {
                        arr[nx - d[k] / 2][ny - d[3 - k] / 2] = '#';
                    }
                }
            }
        }
    }
    for (int i = 0; i < 3 * n; i++) {
        printf("%s\n", arr[i]);
    }
}