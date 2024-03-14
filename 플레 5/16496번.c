#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ull;

int divide(int n) {
    int ten = 1;
    while (n / 10 >= ten) ten *= 10;
    return ten;
}

int comp(const void *a, const void *b) {
    int n = *(int *) a, m = *(int *) b, nt = divide(n), mt = divide(m), ntS, mtS, max;
    ull ten = 1;
    ntS = nt, mtS = mt, max = nt > mt ? nt : mt;
    while (ntS >= ten / max || mtS >= ten / max) {
        if (n / nt != m / mt) return m / mt - n / nt;
        n %= nt, nt /= 10, m %= mt, mt /= 10, ten *= 10;
        if (!nt) nt = ntS, n = *(int *) a;
        if (!mt) mt = mtS, m = *(int *) b;
    }
    return 0;
}

int main(void) {
    int n, arr[1001];
    ull res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]), res += arr[i];
    qsort(arr, n, 4, comp);
    for (int i = 0; i < n; i++) if (res) printf("%d", arr[i]);
    if (!res) printf("0");
}