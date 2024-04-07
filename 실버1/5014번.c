#include <stdio.h>

int main() {
    int F, s, g, u, d, r = 0, f = -1, que[1000001][2];
    char vis[1000001];
    scanf("%d %d %d %d %d", &F, &s, &g, &u, &d);
    que[r][0] = s, que[r][1] = 0;
    while (f < r) {
        int x = que[++f][0], c = que[f][1];
        if (x == g) {
            printf("%d", c);
            return 0;
        }
        if (x + u <= F && !vis[x + u]) vis[x + u] = 1, que[++r][0] = x + u, que[r][1] = c + 1;
        if (x - d >= 1 && !vis[x - d]) vis[x - d] = 1, que[++r][0] = x - d, que[r][1] = c + 1;
    }
    printf("use the stairs");
}