#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
    return *(int *) a - *(int *) b;
}

int main(void) {
    int n, arr[500001] = {0}, all = 0;
    long long int result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        all += arr[i];
    }
    qsort(arr, n, 4, comp);
    for (int i = 0; i < n; i++) {
        all -= arr[i];
        result += arr[i] * all;
    }
    printf("%lld", result);
}