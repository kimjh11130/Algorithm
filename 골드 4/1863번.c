#include <stdio.h>

int main() {
    int n, a, b, stack[50001], t = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        if (i != n) scanf("%d %d", &a, &b);
        else b = 0;
        while (t && stack[t - 1] >= b) {
            if (stack[--t] != b) cnt++;
        }
        stack[t++] = b;
    }
    printf("%d", cnt);
}