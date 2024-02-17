#include <stdio.h>
#include <stdlib.h>

int arr[1025][1025];

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int findTwo(int n, int x, int y) {
    if (n == 1) return arr[x][y];
    int spe[4], dx[] = {0, 0, 1, 1}, dy[] = {0, 1, 0, 1};
    for (int i = 0; i < 4; i++) {
        spe[i] = findTwo(n / 2, x + dx[i] * n / 2, y + dy[i] * n / 2);
    }
    qsort(spe, 4, 4, comp);
    return spe[1];
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d", findTwo(n, 0, 0));
}