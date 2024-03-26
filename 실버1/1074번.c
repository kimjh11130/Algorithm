#include <stdio.h>

int n, r, c, max = 1, res;

void divide(int x, int y, int cnt) {
    if (!max) {
        res = cnt;
    } else {
        max /= 2;
        if (x + max > r) {
            if (y + max <= c) y += max, cnt += max * max;
        } else {
            if (y + max > c)x += max, cnt += max * max * 2;
            else x += max, y += max, cnt += max * max * 3;
        }
        divide(x, y, cnt);
    }
}

int main() {
    scanf("%d %d %d", &n, &r, &c);
    while (n--) max *= 2;
    divide(0, 0, 0);
    printf("%d", res);
}
