#include <stdio.h>
#include <stdlib.h>

int n = 0, arr[1000][1000] = {0}, cnt = 0;

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int dfs(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1) {
        arr[x][y] = 0;
        cnt++;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    }
    return 0;
}

int main(void){
    int count[1000] = { 0 }, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(arr[i][j]){
                dfs(i, j);
                count[r++] = cnt;
                cnt = 0;
            }
        }
    }
    printf("%d\n", r);
    qsort(count, r, 4, comp);
    for (int i = 0; i < r; i++) {
        printf("%d\n", count[i]);
    }
}