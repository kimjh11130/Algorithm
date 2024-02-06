#include <stdio.h>

int n, cnt, i = 1;

int main() {
    scanf("%d", &n);
    while (cnt <= n)cnt += i++;
    printf("%d", i % 2 ? 0 : cnt - n);
}