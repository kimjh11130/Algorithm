#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, k, a[100001] = {0}, d[100001] = {0}, cnt = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, 4, comp);
    for (int i = 0; i < n; i++) {
        d[i] = i ? a[i] - a[i - 1] : a[i];
    }
    qsort(d, n, 4, comp);
    for (int i = n - 1; i >= 0; i--) {
        if (k) k--;
        else cnt += d[i];
    }
    printf("%d", cnt);
}