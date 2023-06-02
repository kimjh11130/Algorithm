#include <stdio.h>
int memo[1001][1001] = {0};

int divide(int a){
    return a % 10007;
}

int combination(int n, int r){
    if(n == r || r == 0) {
        return 1;
    } else if(n-r == 1 || r == 1){
        return n;
    }
    else{
        if(memo[n][r] != 0){
            return divide(memo[n][r]);
        } else {
            memo[n][r] = combination(n-1, r) + combination(n-1,r-1);
            return divide(memo[n][r]);
        }
    }
}

int main(void){
    int n, r;
    scanf("%d %d",&n ,&r);
    printf("%d", combination(n, r));
}