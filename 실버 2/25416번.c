#include <stdio.h>

int arr[5][5], r = 0, f = 0;
struct coordinate {
    int x;
    int y;
    int c;
};
struct coordinate que[101];

int bfs(int x1, int y1){
    que[++r].x = x1;
    que[r].y = y1;
    que[r].c = -1;
    while (r > f){
        int x = que[++f].x;
        int y = que[f].y;
        int count = que[f].c + 1;
        if(arr[x][y] == 1){
            return count;
        }
        arr[x][y] = 2;
        if(x > 0 && arr[x-1][y] != -1 && arr[x-1][y] != 2){
            que[++r].x = x-1;
            que[r].y = y;
            que[r].c = count;
        }
        if(y < 4 && arr[x][y+1] != -1 && arr[x][y+1] != 2) {
            que[++r].x = x;
            que[r].y = y + 1;
            que[r].c = count;
        }
        if(y > 0 && arr[x][y-1] != -1 && arr[x][y-1] != 2){
            que[++r].x = x;
            que[r].y = y-1;
            que[r].c = count;
        }
        if(x < 4 && arr[x+1][y] != -1 && arr[x+1][y] != 2){
            que[++r].x = x+1;
            que[r].y = y;
            que[r].c = count;
        }
    }
    return -1;
}

int main(void){
    int x, y, cnt = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d %d", &x, &y);
    cnt = bfs(x,y);
    printf("%d", cnt);
    return 0;
}