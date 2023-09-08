#include <stdio.h>

int main() {
    int n, a = 2, cnt = 0;
    scanf("%d", &n), n -= 1;
    while (n >= a) n -= a, a *= 2, cnt++;
    for (int i = cnt; i >= 0; i--) printf("%d", n >> i & 1 ? 7 : 4);
}