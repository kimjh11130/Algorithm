#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, arr[500001] = {0}, cpp[8001] = {0}, m, all = 0, max = 0, a, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        arr[i] = m, cpp[m + 4000]++, all += m;
        max = max > cpp[m + 4000] ? max : cpp[m + 4000];
    }
    for (int i = 0; i < 8001; i++) {
        if (cpp[i] == max) {
            a = i - 4000, c++;
            if (c == 2)break;
        }
    }
    qsort(arr, n, 4, comp);
    printf("%d\n%d\n%d\n%d", (int) round((double) all / n), arr[n / 2], a, arr[n - 1] - arr[0]);
}