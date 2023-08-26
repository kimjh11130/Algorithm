#include <stdio.h>

int find(int a) {
    int n = 0;
    while (a) {
        if (a % 10 == 6)n++;
        else n = 0;
        if (n == 3) return 1;
        a /= 10;
    }
    return 0;
}

int main(void) {
    int n, i = 665, cnt = 0;
    scanf("%d", &n);
    while (cnt != n) {
        i++;
        if (find(i)) cnt++;
    }
    printf("%d", i);
}