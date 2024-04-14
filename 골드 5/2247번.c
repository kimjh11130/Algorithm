#include <stdio.h>

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 2; i < n / 2 + 1; i++) {
        cnt = (cnt + (n / i - 1) * i) % (int) 1e6;
    }
    printf("%d", cnt);
}