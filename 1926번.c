#include <stdio.h>

int x1 = 0, y1 = 0, arr[502][502] = {0}, cnt = 0;

int dfs(int x, int y) {
    if (x >= 0 && y >= 0 && x < x1 && y < y1 && arr[x][y] == 1) {
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
    int r = 0, max = 0;
    scanf("%d %d", &x1, &y1);
    for (int i = 0; i < x1; i++) {
        for (int j = 0; j < y1; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    for (int i = 0; i < x1; i++) {
        for (int j = 0; j < y1; j++) {
            if(arr[i][j]){
                dfs(i, j);
                if(cnt > max){
                    max = cnt;
                }
                cnt = 0;
                r++;
            }
        }
    }
    printf("%d\n", r);
    printf("%d\n", max);
}