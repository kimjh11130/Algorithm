#include <stdio.h>

int main(void) {
    int n, f = 1, l = 1, a, b, cnt = 1;
    scanf("%d", &n);
    while (1) {
        a = f * f, b = l * l;
        if (f - l == 1 && a - b > n) break;
        if (a - b == n) cnt = 0, printf("%d\n", f);
        if (a - b >= n) l++;
        else f++;
    }
    if (cnt) printf("-1");
}