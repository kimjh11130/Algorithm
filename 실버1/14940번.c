#include <stdio.h>

typedef struct element {
    int x, y, c;
} element;


int n, m, r = -1, f = -1, arr[1002][1002], result[1002][1002], d[] = {0, -1, 0, 1};
element que[1000004];

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 2) que[++r].x = i, que[r].y = j, que[r].c = 0;
        }
    }
    while (f < r) {
        int x = que[++f].x, y = que[f].y, c = que[f].c;
        for (int i = 0; i < 4; i++) {
            int nx = d[i] + x, ny = d[3 - i] + y;
            if (arr[nx][ny] == 1 && result[nx][ny] == 0) {
                result[nx][ny] = c + 1;
                que[++r].x = nx, que[r].y = ny, que[r].c = c + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(arr[i][j] == 1 && result[i][j] == 0){
                printf("-1 ");
            } else{
                printf("%d ", result[i][j]);
            }
        }
        printf("\n");
    }
}