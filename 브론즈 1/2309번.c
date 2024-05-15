#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int arr[9], res = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]), res += arr[i];
    }
    qsort(arr, 9, 4, comp);
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (res - arr[i] - arr[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j)printf("%d\n", arr[k]);
                }
                return 0;
            }
        }
    }
}
