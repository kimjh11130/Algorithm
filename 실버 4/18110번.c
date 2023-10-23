#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    int n, arr[400000] = {0}, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, 4, comp);
    int a = round((double) n * 15 / 100);
    for (int i = a; i < n - a; i++)c += arr[i];
    printf("%d", n == 0 ? 0 : (int) round((double) c / (n - 2 * a)));
}