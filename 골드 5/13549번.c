#include <stdio.h>

#define MAX 140000

typedef struct element {
    int x, c;
} element;

int main() {
    int n, k, vis[MAX] = {0}, r = 0, f = -1;
    element que[MAX];
    scanf("%d %d", &n, &k);
    que[r].x = n, que[r].c = 0, vis[n] = 1;
    while (f < r) {
        int x = que[++f].x, c = que[f].c;
        if (x == k) {
            printf("%d", c);
            return 0;
        }
        if (x < k && x * 2 < MAX && !vis[x * 2]) que[f].x = x * 2, que[f].c = c, vis[x * 2] = 1, f--;
        if (x && !vis[x - 1]) que[++r].x = x - 1, que[r].c = c + 1, vis[x - 1] = 1;
        if (x < k && !vis[x + 1]) que[++r].x = x + 1, que[r].c = c + 1, vis[x + 1] = 1;
    }
}
