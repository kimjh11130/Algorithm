#include <stdio.h>

int five(int a) {
    int n = 0;
    while (a % 5 == 0) a /= 5, n++;
    return n;
}

int main(void) {
    int i, n, cnt = 0;
    scanf("%d", &n);
    for (i = 5; n > cnt; i += 5) {
        cnt += five(i);
    }
    printf("%d", n == cnt ? i - 5 : -1);
}