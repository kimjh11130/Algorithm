#include<stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void){
    int n, arr[1001] = {0}, value = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    for (int i = 0; i < n; i++) {
        value += arr[i];
        arr[i+1] += arr[i];
    }
    printf("%d", value);
}