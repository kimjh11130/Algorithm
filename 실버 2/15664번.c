#include <stdio.h>
#include <stdlib.h>

int n, m, i, arr[9], vis[9], res[9];

void back() {
    if (i == m) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", res[j]);
        }
        printf("\n");
    } else {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && tmp != arr[j] && res[i] <= arr[j]) {
                vis[j] = 1, res[++i] = arr[j], tmp = arr[j];
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
        scanf("%d", &arr[j]);
    }
    qsort(arr, n, 4, comp);
    back();
}