#include <stdio.h>

int main() {
    int n, a, b;
    char sosu[1000004] = {0};
    for (int i = 2; i < 1000; i++) {
        if (!sosu[i]) {
            for (int j = i * 2; j < 1000004; j += i) sosu[j] = 1;
        }
    }
    scanf("%d", &n);
    while (n) {
        a = 3;
        while (1) {
            if (!sosu[a] && !sosu[n - a]) break;
            else a += 2;
        }
        printf("%d = %d + %d\n", n, a, n - a);
        scanf("%d", &n);
    }
}