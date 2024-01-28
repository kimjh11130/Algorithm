#include <stdio.h>

int a, b, cnt;

void dfs(long long int n) {
    if (n > b) return;
    if (n >= a) cnt++;
    dfs(n * 10 + 4);
    dfs(n * 10 + 7);
}

int main(void) {
    scanf("%d %d", &a, &b);
    dfs(0);
    printf("%d", cnt);
}