#include <stdio.h>

struct element{
    int x;
    int c;
};

int a, b, n, arr[1001][1001] = {0};
int r = -1, f = -1;
struct element q[20003] = {0};

int bfs(int z){
    q[++r].x = z;
    q[r].c = 0;
    while(f < r){
        int x = q[++f].x;
        int co = q[f].c;
        if(x == b){
            return co;
        }
        for (int i = 1; i <= n; ++i) {
            if(arr[x][i]){
                arr[x][i] = 0;
                q[++r].x = i;
                q[r].c = co + 1;
            }
        }
    }
    return -1;
}

int main(void){
    int m, x, y;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    printf("%d", bfs(a));
}