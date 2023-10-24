#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int x, y;
} element;

int comp(const void *a, const void *b) {
    if (((element *) a)->y == ((element *) b)->y) {
        return ((element *) a)->x - ((element *) b)->x;
    } else {
        return ((element *) a)->y - ((element *) b)->y;
    }
}

int main(void) {
    int n;
    element arr[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, n, sizeof arr[0], comp);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
}
