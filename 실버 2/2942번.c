#include <stdio.h>

int uclid(int a, int b) {
    int r = a % b;
    return r ? uclid(b, r) : b;
}

int main() {
    int r, g, a;
    scanf("%d %d", &r, &g);
    a = uclid(r, g);
    for (int i = 1; i * i <= a; i++) {
        if (!(a % i)) {
            printf("%d %d %d\n", i, r / i, g / i);
            if (i * i != a) printf("%d %d %d\n", a / i, r / (a / i), g / (a / i));
        }
    }
}