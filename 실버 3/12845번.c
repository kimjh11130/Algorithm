#include <stdio.h>

int n, m, a, b, i;
int main() {
    scanf("%d", &n);
    for (; i < n; i++) {
        scanf("%d", &a), b += a;
        if (a > m) m = a;
    }
    printf("%d", b + m * (n - 2));
}