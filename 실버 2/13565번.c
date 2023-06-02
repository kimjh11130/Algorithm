#include <stdio.h>

int cnt = 0;
char memo[1001][1001];

int checks(int x,int y){
    if(memo[x][y] != '0'){
        return 0;
    }
    if(x == 0){
        cnt = 1;
        return 1;
    }
    memo[x][y] = '1';
    checks(x+1,y);
    checks(x-1,y);
    checks(x,y+1);
    checks(x,y-1);
    return 0;
}

int main(void){
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < x; i++) {
        scanf("%s", memo[i]);
    }
    for (int i = 0; i < y; ++i) {
        checks(x-1,i);
    }
    if(cnt == 1){
        printf("YES");
    }else{
        printf("NO");
    }
}