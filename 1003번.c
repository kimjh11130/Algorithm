#include <stdio.h>

int main(void){
    int t, n;
    int memo[40] = {1,1};
    for (int i = 2; i < 40; i++) {
        memo[i] = memo[i-1] + memo[i-2];
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        if(n == 0){
            printf("1 0\n");
            continue;
        } else if(n == 1) {
            printf("0 1\n");
            continue;
        } else{
            printf("%d %d\n", memo[n - 2], memo[n - 1]);
        }
    }
}