#include <stdio.h>

int u(int a, int b) { return a % b ? u(b, a % b) : b; }

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b), c = u(a, b);
        printf("%d %d\n", a / c * b, c);
    }
}