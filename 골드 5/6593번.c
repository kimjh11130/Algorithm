#include <stdio.h>

typedef struct element {
    int z, x, y, c;
} element;

int main(void) {
    while (1) {
        int L, R, C, r = -1, f = -1, a = 0, d[] = {0, 0, 1, 0, 0, -1};
        char arr[32][32][32] = {0};
        element que[27000] = {0};
        scanf("%d %d %d", &L, &R, &C);
        if (L + R + C == 0) return 0;
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= R; j++) {
                for (int k = 1; k <= C; k++) {
                    scanf(" %1c", &arr[i][j][k]);
                    if (arr[i][j][k] == 'S') que[++r].z = i, que[r].x = j, que[r].y = k, que[r].c = 0;
                }
            }
        }
        while (r > f) {
            int z = que[++f].z, x = que[f].x, y = que[f].y, c = que[f].c;
            for (int i = 0; i < 6; i++) {
                int nz = z + d[i % 6], nx = x + d[(i + 1) % 6], ny = y + d[(i + 2) % 6];
                if (arr[nz][nx][ny] == 'E') {
                    r = 0, a = 1;
                    break;
                } else if (arr[nz][nx][ny] == '.') {
                    arr[nz][nx][ny] = '#';
                    que[++r].z = nz, que[r].x = nx, que[r].y = ny, que[r].c = c + 1;
                }
            }
        }
        if (a) printf("Escaped in %d minute(s).\n", que[f].c + 1);
        else printf("Trapped!\n");
    }
}