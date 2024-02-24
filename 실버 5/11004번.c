#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    int n, k, arr[5000000] = {0};
    scanf("%d %d", &n,&k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    printf("%d", arr[k-1]);
}