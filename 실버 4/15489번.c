#include <stdio.h>

int memo[31][31] = {0};

int Pascal(int x, int y){
    if(y == 0 || x == 0){
        return 0;
    } else if(y == 1 || x == y){
        memo[x][y] = 1;
        return memo[x][y];
    } else {
        if(memo[x][y] != 0){
            return memo[x][y];
        } else{
            memo[x][y] = Pascal(x-1, y) + Pascal(x-1, y-1);
            return memo[x][y];
        }
    }
}

int main(void){
    int row, column, width, x, y, cnt = 0;
    scanf("%d %d %d", &row, &column, &width);
    x = row + width;
    y = column + 1;
    for (int i = row; i < x; ++i, ++y) {
        for (int j = column; j < y; ++j) {
            cnt += Pascal(i, j);
        }
    }
    printf("%d", cnt);
}