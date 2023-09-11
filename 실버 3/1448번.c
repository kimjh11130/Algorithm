#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, arr[1000001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    for (int i = 0; i <= n - 3; i++) {
        if (arr[i] < arr[i + 1] + arr[i + 2]) {
            printf("%d", arr[i] + arr[i + 1] + arr[i + 2]);
            return 0;
        }
    }
    printf("-1");
}