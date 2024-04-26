#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, res = -1000, cur, tmp = -1000;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &cur);
        tmp = max(cur, tmp + cur);
        res = max(tmp, res);
    }
    printf("%d", res);
}