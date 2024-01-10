#include <stdio.h>
#include <stdlib.h>

int n, m, i, arr[9], ar[9], vis[9];

void back() {
    if (m == i) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    } else {
        for (int j = 0; j < n; j++) {
            if (!vis[j] && arr[i] <= ar[j]) {
                vis[j] = 1, arr[++i] = ar[j];
                back();
                vis[j] = 0, i--;
            }
        }
    }
}

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int j = 0; j < n; j++) {
        scanf("%d", &ar[j]);
    }
    qsort(ar, n, 4, comp);
    back();
}