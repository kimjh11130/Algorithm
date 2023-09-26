#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    int s, arr[51] = {0}, n, cnt = -1;
    scanf("%d", &s);
    for (int i = 0; i < s; i++) scanf("%d", &arr[i]);
    scanf("%d", &n);
    qsort(arr, s, 4, comp);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= n) {
            if (i == 0) cnt += (n - 0) * (arr[i] - n);
            else cnt += (n - arr[i - 1]) * (arr[i] - n);
            break;
        }
    }
    printf("%d", cnt == -1 ? 0 : cnt);
}