#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    int n, m, c = 0;
    long long int p;
    scanf("%d %d %lld", &n, &m, &p);
    for (int i = 0; i < n; i++) {
        int arr[501] = {0};
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[j]);
        }
        qsort(arr, m, 4, comp);
        for (int j = 0; j < m; j++) {
            if (arr[j] == -1) c++;
            else if (p >= arr[j])p += arr[j];
            else {
                while (c > 0) {
                    p *= 2, c--;
                    if (p >= arr[j]) {
                        p += arr[j];
                        break;
                    }
                }
                if (p >= arr[j]) continue;
                else {
                    printf("0");
                    return 0;
                }
            }
        }
        while (c > 0) p *= 2, c--;
    }
    printf("1");
}