#include <stdio.h>

int n, m, arr[200][200] = { 0 }, r = 0, f = 0;
struct element{
    int x;
    int y;
    int c;
};
struct element que[100000];

int bfs(int x1, int y1){
    que[++r].x = x1;
    que[r].y = y1;
    que[r].c = 1;
    while (f < r){
        int x = que[++f].x;
        int y = que[f].y;
        int c = que[f].c;
        arr[x][y] = 0;
        if(x == n && y == m){
            return que[f].c;
        }
        if(arr[x+1][y] == 1){
            arr[x+1][y] = 0;
            que[++r].x = x + 1;
            que[r].y = y;
            que[r].c = c + 1;
        }
        if(arr[x-1][y] == 1){
            arr[x-1][y] = 0;
            que[++r].x = x - 1;
            que[r].y = y;
            que[r].c = c + 1;
        }
        if(arr[x][y+1] == 1){
            arr[x][y+1] = 0;
            que[++r].x = x;
            que[r].y = y + 1;
            que[r].c = c + 1;
        }if(arr[x][y - 1] == 1){
            arr[x][y-1] = 0;
            que[++r].x = x;
            que[r].y = y - 1;
            que[r].c = c + 1;
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    printf("%d", bfs(1,1));
}