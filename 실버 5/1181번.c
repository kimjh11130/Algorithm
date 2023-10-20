#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct element {
    int size;
    char arr[51];
} element;

int comp(const void *a, const void *b) {
    if (((element *) a)->size == ((element *) b)->size) {
        for (int i = 0; i < ((element *) a)->size; i++) {
            if (((element *) a)->arr[i] != ((element *) b)->arr[i]) {
                return ((element *) a)->arr[i] - ((element *) b)->arr[i];
            }
        }
        return 0;
    } else {
        return ((element *) a)->size - ((element *) b)->size;
    }
}

int main(void) {
    int n;
    element arr[20001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i].arr);
        arr[i].size = strlen(arr[i].arr);
    }
    qsort(arr, n, sizeof(element), comp);
    for (int i = 1; i <= n; i++) {
        if (strcmp(arr[i].arr, arr[i - 1].arr) != 0) {
            printf("%s\n", arr[i - 1].arr);
        }
    }
}
