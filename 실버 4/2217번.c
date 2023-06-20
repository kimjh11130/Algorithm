#include<stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main(void) {
    int n, arr[100003] = {0}, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    for (int i = 0; i < n; ++i) {
        arr[i] = arr[i] * (i + 1);
    }
    qsort(arr, n, 4, comp);
    printf("%d", arr[0]);
}