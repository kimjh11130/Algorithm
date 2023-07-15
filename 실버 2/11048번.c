#include <stdio.h>

int main(void){
    int x, y, memo[1001][1001];
    scanf("%d %d", &x,&y);
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            scanf("%d", &memo[i][j]);
            memo[i][j] += memo[i-1][j] > memo[i][j-1] ? memo[i-1][j] : memo[i][j-1];
        }
    }
    printf("%d", memo[x][y]);
}