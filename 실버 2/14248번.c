#include <stdio.h>

int main(void) {
    int n, r = 0, f = -1, cnt = 0, ai[100001] = {0}, vis[100001] = {0}, que[100001] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ai[i]);
    }
    scanf("%d", &que[r]), vis[que[r]] = 1;
    while (f < r){
        int x = que[++f];
        if(x + ai[x] <= n && vis[x + ai[x]] == 0){
            que[++r] = x + ai[x];
            vis[x + ai[x]] = 1;
        }
        if(x - ai[x] > 0 && vis[x - ai[x]] == 0){
            que[++r] = x - ai[x];
            vis[x - ai[x]] = 1;
        }
        cnt++;
    }
    printf("%d", cnt);
}