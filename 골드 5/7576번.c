#include <stdio.h>

struct element {
    int x;
    int y;
    int c;
};

struct element que[1000000] = {0};
int r = -1, f = -1;

int main(void) {
    int m, n, arr[1001][1001] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1) {
                que[++r].x = i;
                que[r].y = j;
                que[r].c = 0;
            }
        }
    }
    while (f < r) {
        int x = que[++f].x;
        int y = que[f].y;
        int c = que[f].c;
        if (x != m-1 && arr[x + 1][y] == 0) {
            que[++r].x = x + 1;
            que[r].y = y;
            que[r].c = c + 1;
            arr[x + 1][y] = 1;
        }
        if (x != 0 && arr[x - 1][y] == 0) {
            que[++r].x = x - 1;
            que[r].y = y;
            que[r].c = c + 1;
            arr[x - 1][y] = 1;
        }
        if (y != n-1 && arr[x][y + 1] == 0) {
            que[++r].x = x;
            que[r].y = y + 1;
            que[r].c = c + 1;
            arr[x][y + 1] = 1;
        }
        if (y != 0 && arr[x][y - 1] == 0) {
            que[++r].x = x;
            que[r].y = y - 1;
            que[r].c = c + 1;
            arr[x][y - 1] = 1;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!arr[i][j]){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", que[r].c);
}