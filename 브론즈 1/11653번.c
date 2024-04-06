#include <stdio.h>

int main() {
    int n, i = 2;
    scanf("%d", &n);
    while (n - 1) {
        if (n % i)i++;
        else n /= i, printf("%d\n", i);
    }
}