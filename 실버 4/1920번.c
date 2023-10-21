#include <stdio.h>
#include <stdlib.h>

int n, arr[100001];

int comp(const void *a, const void *b) {
    if (*(int *) a > *(int *) b)return 1;
    else if (*(int *) a < *(int *) b)return -1;
    else return 0;
}

int binary(int a) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == a) return 1;
        else if (arr[mid] > a)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}

int main() {
    int a, g;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    scanf("%d", &g);
    for (int i = 0; i < g; i++) {
        scanf("%d", &a);
        printf("%d\n", binary(a));
    }
}