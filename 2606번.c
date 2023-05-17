#include <stdio.h>

int r = 0, f = 0, n = 0;
int arr[101][101] = {0};
int visit[101] = {0};
int que[101] = {0};

void bfs(int x){
    que[++r] = x;
    while (f < r){
        int x1 = que[++f];
        for (int i = 0; i <= n; i++) {
            if(arr[x1][i] && !visit[i]){
                visit[i]++;
                que[++r] = i;
            }
        }
    }
}

int main(void){
    int com, a, b, c = 0;
    scanf("%d",&n);
    scanf("%d", &com);
    for (int i = 0; i < com; ++i) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    bfs(1);
    for (int i = 0; i <= n; ++i) {
        if(visit[i]) c++;
    }
    printf("%d", c - 1);
}