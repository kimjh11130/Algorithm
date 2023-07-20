#include <stdio.h>

struct element{
    int x;
    int y;
    int z;
    int c;
};

struct element que[1000000] = {0};
int f = -1, r = -1;

int main(void) {
    int m, n, h, arr[101][101][101] = {0};
    scanf("%d %d %d", &m, &n, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &arr[i][j][k]);
                if(arr[i][j][k] == 1){
                    que[++r].x = k;
                    que[r].y = j;
                    que[r].z = i;
                    que[r].c = 0;
                }
            }
        }
    }
    while (f < r){
        int x = que[++f].x;
        int y = que[f].y;
        int z = que[f].z;
        int c = que[f].c;
        if(z != 0 && arr[z-1][y][x] == 0){
            que[++r].x = x;
            que[r].y = y;
            que[r].z = z - 1;
            que[r].c = c + 1;
            arr[z-1][y][x] = 1;
        }
        if(z != h - 1 && arr[z+1][y][x] == 0){
            que[++r].x = x;
            que[r].y = y;
            que[r].z = z + 1;
            que[r].c = c + 1;
            arr[z+1][y][x] = 1;
        }
        if(y != 0 && arr[z][y - 1][x] == 0){
            que[++r].x = x;
            que[r].y = y - 1;
            que[r].z = z;
            que[r].c = c + 1;
            arr[z][y - 1][x] = 1;
        }
        if(y != n - 1 && arr[z][y + 1][x] == 0){
            que[++r].x = x;
            que[r].y = y + 1;
            que[r].z = z;
            que[r].c = c + 1;
            arr[z][y + 1][x] = 1;
        }
        if(x != 0 && arr[z][y][x - 1] == 0){
            que[++r].x = x - 1;
            que[r].y = y;
            que[r].z = z;
            que[r].c = c + 1;
            arr[z][y][x - 1] = 1;
        }
        if(x != m - 1 && arr[z][y][x + 1] == 0){
            que[++r].x = x + 1;
            que[r].y = y;
            que[r].z = z;
            que[r].c = c + 1;
            arr[z][y][x + 1] = 1;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if(arr[i][j][k] == 0){
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    printf("%d", que[r].c);
}