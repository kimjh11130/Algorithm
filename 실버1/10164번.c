#include <stdio.h>

long long int pac(int n, int m) {
    long long int a = 1, b = 1;
    for (int i = n + 1; i <= n + m; i++) a *= i;
    for (int i = 1; i <= m; i++) b *= i;
    return a / b;
}

int main() {
    int n, m, k;
    long long int a, b;
    scanf("%d %d %d", &n, &m, &k);
    if (k == 0) a = 1, b = pac(n - 1, m - 1);
    else if (k % m) a = pac(k / m, k % m - 1), b = pac(n - k / m - 1, m - k % m);
    else a = pac(k / m - 1, m - 1), b = pac(n - k / m, 0);
    printf("%lld", a * b);
}