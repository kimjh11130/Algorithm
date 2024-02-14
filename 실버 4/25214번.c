#include <stdio.h>

int small(int a, int b) { return a > b ? b : a; }

int main() {
    int n, arr[200001] = {0}, min[200001] = {0}, max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i) min[i] = small(min[i - 1], arr[i]);
        else min[i] = arr[i];
    }
    printf("0 ");
    for (int i = 1; i < n; i++) {
        if (arr[i] - min[i] > arr[max] - min[max]) max = i;
        printf("%d ", arr[max] - min[max]);
    }
}