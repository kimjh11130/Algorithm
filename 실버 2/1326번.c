#include <stdio.h>

typedef struct element {
    int x, c;
} element;
element que[250000];

int main() {
    int n, arr[10001] = {0}, a, b, f = -1, r = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &a, &b);
    que[++r].x = a, que[r].c = 0;
    while (f < r) {
        int x = que[++f].x, c = que[f].c;
        if (x == b) {
            printf("%d", c);
            return 0;
        } else {
            for (int i = 1; x + arr[x] * i <= n; i++) {
                que[++r].x = x + arr[x] * i;
                que[r].c = c + 1;
            }
            for (int i = -1; x + arr[x] * i >= 1; i--) {
                que[++r].x = x + arr[x] * i;
                que[r].c = c + 1;
            }
        }
    }
    printf("-1");
}