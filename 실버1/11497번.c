#include <stdio.h>
#include <stdlib.h>

int arr[10001] = {0};

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    int t, max;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int maxLength = 0;
        scanf("%d", &max);
        for (int j = 0; j < max; j++) {
            scanf("%d", &arr[j]);
        }
        qsort(arr, max, 4, comp);
        int arr1[10001] = {0}, c = 0;
        for (int j = 0; j < max; j++) {
            if(j % 2 == 0) arr1[c++] = arr[j];
        }
        for (int j = max - 1; j >= 0; j--) {
            if(j % 2 == 1) arr1[c++] = arr[j];
        }
        for (int j = 1; j < max; ++j) {
            if(abs(arr1[j] - arr1[j-1]) > maxLength) maxLength = abs(arr1[j] - arr1[j-1]);
        }
        printf("%d\n", maxLength);
    }
    return 0;
}