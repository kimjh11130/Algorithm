#include <stdio.h>

int main(void) {
    int n, a = 1;
    scanf("%d", &n);
    while (n > 4) {
        a = a * 3 % 10007;
        n -= 3;
    }
    printf("%d", a * n % 10007);
}