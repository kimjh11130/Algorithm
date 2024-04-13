#include <stdio.h>

#define MAX 100001

int main() {
    int a, b, n, m, que[MAX][2], r = 0, f = -1;
    char vis[MAX] = {0};
    scanf("%d %d %d %d", &a, &b, &n, &m);
    que[r][0] = n, que[r][1] = 0;
    while (f < r) {
        int x = que[++f][0], c = que[f][1], tmp;
        if (x == m) {
            printf("%d", c);
            return 0;
        }
        tmp = x * a;
        if (tmp < MAX && !vis[tmp]) vis[tmp] = 1, que[++r][0] = tmp, que[r][1] = c + 1;
        tmp = x * b;
        if (tmp < MAX && !vis[tmp]) vis[tmp] = 1, que[++r][0] = tmp, que[r][1] = c + 1;
        tmp = x + a;
        if (tmp < MAX && !vis[tmp]) vis[tmp] = 1, que[++r][0] = tmp, que[r][1] = c + 1;
        tmp = x + b;
        if (tmp < MAX && !vis[tmp]) vis[tmp] = 1, que[++r][0] = tmp, que[r][1] = c + 1;
        tmp = x + 1;
        if (tmp < MAX && !vis[tmp]) vis[tmp] = 1, que[++r][0] = tmp, que[r][1] = c + 1;
        tmp = x - 1;
        if (tmp > 0 && !vis[tmp]) vis[tmp] = 1, que[++r][0] = tmp, que[r][1] = c + 1;
        tmp = x - a;
        if (tmp > 0 && !vis[tmp]) vis[tmp] = 1, que[++r][0] = tmp, que[r][1] = c + 1;
        tmp = x - b;
        if (tmp > 0 && !vis[tmp]) vis[tmp] = 1, que[++r][0] = tmp, que[r][1] = c + 1;
    }
}
