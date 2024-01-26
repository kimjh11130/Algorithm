#include <stdio.h>

int main(void) {
    int l, u, fsosu[1000001] = {0}, arr[1000001] = {0};
    for (int i = 2; i <= 1000; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j < 1000001; j += i) {
                arr[j] = 1;
            }
        }
    }
    arr[2] = fsosu[2] = 1;
    for (int i = 3; i < 1000001; i++) {
        fsosu[i] = fsosu[i - 1];
        if (!arr[i]) {
            if (i % 4 == 1) fsosu[i] += 1;
            arr[i] = arr[i - 1] + 1;
        } else arr[i] = arr[i - 1];
    }
    scanf("%d %d", &l, &u);
    while (u != -1 || l != -1) {
        printf("%d %d ", l, u);
        if (l > 1) printf("%d %d\n", arr[u] - arr[l - 1], fsosu[u] - fsosu[l - 1]);
        else if (u > 0) printf("%d %d\n", arr[u], fsosu[u]);
        else printf("%d %d\n", 0, 0);
        scanf("%d %d", &l, &u);
    }
}