#include <stdio.h>

typedef struct element {
    int x, c;
} element;

struct element que[102];

int main(void) {
    int n, m, a, b, arr[101] = {0}, r = -1, f = -1, vis[101] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++) {
        scanf("%d %d", &a, &b);
        arr[a] = b;
    }
    que[++r].x = 1, que[r].c = 0;
    while (f < r) {
        int x = que[++f].x, c = que[f].c;
        if (x >= 100) {
            printf("%d", c);
            return 0;
        } else {
            for (int i = 1; i <= 6; i++) {
                if (x + i > 100) break;
                if (vis[x + i] == 1) continue;
                que[++r].x = x + i, que[r].c = c + 1;
                vis[x + i] = 1;
                if (arr[x + i] != 0) que[r].x = arr[x + i];
            }
        }
    }
}