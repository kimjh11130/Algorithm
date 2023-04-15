#include <stdio.h>

int memo[6][6] ={0};
int allValue[1000000] = {0};

int check(int x, int y, int cnt, int value){
    int news = value;
    if(x < 0 || y < 0 || x > 4 || y > 4){
        return  0;
    }
    if(cnt == 6) {
        allValue[value]++;
        return 0;
    }
    if(cnt != 0){
        news = value * 10 + memo[x][y];
    }
    check(x+1,y,cnt+1, news);
    check(x-1,y,cnt+1,news);
    check(x,y+1,cnt+1,news);
    check(x,y-1,cnt+1,news);
    return 0;
}

int main(void){
    int result = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &memo[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int cnt = 0;
            check(i,j, cnt, memo[i][j]);
        }
    }
    for (int i = 0; i < 1000000; i++) {
        if(allValue[i] != 0){
            result++;
        }
    }
    printf("%d", result);
}