#include <stdio.h>

long long int pow(long long int a) { return a * a; };

long long int max(long long int a, long long int b) { return a > b ? a : b; }

long long int min(long long int a, long long int b) { return a > b ? b : a; }

int main(void) {
    int n, cnt = 0;
    long long int x[1501] = {0}, y[1501] = {0}, a, b, c, d, e, f;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                a = pow(x[i] - x[j]) + pow(y[i] - y[j]);
                b = pow(x[i] - x[k]) + pow(y[i] - y[k]);
                c = pow(x[j] - x[k]) + pow(y[j] - y[k]);
                d = max(max(a, b), max(b, c));
                e = min(min(a, b), min(b, c));
                f = a + b + c - d - e;
                if (d == e + f)cnt++;
            }
        }
    }
    printf("%d", cnt);
}
