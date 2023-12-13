#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int n, arr[51] = {0}, c = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        qsort(arr, n, 4, comp);
        for (int j = 1; j < n; j++) {
            c = c > arr[j] - arr[j - 1] ? c : arr[j] - arr[j - 1];
        }
        printf("Class %d\nMax %d, Min %d, Largest gap %d\n", i + 1, arr[n - 1], arr[0], c);
    }
}