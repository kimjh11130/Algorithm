#include <stdio.h>

int main() {
    int m, t = 0, cnt = 0, a;
    scanf("%d", &m);
    a = (m + 2) / 3;
    if (m == 1) cnt = 1;
    for (int i = 2; i <= 1000000; i++) {
        while (m % i == 0) {
            if (i == 2) t++;
            else cnt++;
            m /= i;
        }
    }
    printf("%d %d", a, cnt + t / 2 + t % 2);
}
