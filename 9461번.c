#include "stdio.h"

long long int memo[101] = {1,1,1};

int main(void){
    int n, what;
    scanf("%d", &n);
    for (int i = 3; i < 100; ++i) {
        memo[i] = memo[i-2] + memo[i-3];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &what);
        printf("%lld\n", memo[what-1]);
    }
}