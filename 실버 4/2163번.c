#include <stdio.h>
int main() {
    int n, que[1000000] = {0}, r, f = 1;
    scanf("%d", &n);
    for (r = 1; r <= n; r++) {
        que[r] = r;
    }
    r -= 1;
    while(f < r){
        que[++r] = que[++f];
        f += 1;
    }
    printf("%d", que[r]);
}