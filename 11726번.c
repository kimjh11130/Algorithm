#include <stdio.h>

int main(void){
    int n, memo[10001] = {1,1};
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        memo[i] = (memo[i-1] + memo[i-2]) % 10007;
    }
    printf("%d\n", memo[n]);
}