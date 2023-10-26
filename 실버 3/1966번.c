#include <stdio.h>

typedef struct element {
    int num, me, cnt;
} element;

int main(void) {
    int t, n, m;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int a, r = -1, f = -1, arr[10] = {0}, cnt = 1;
        element que[10000] = {0};
        scanf("%d %d", &n, &m);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a);
            arr[a - 1]++, que[++r].num = a;
            que[r].me = r == m ? 1 : 0;
        }
        for (int j = 8; j > 0; j--) arr[j] += arr[j + 1];
        while (r > f) {
            int x = que[++f].num, y = que[f].me;
            if (arr[x] < cnt) {
                if (y == 1) {
                    printf("%d\n", cnt);
                    break;
                } else cnt++;
            } else que[++r].num = x, que[r].me = y;
        }
    }
}
