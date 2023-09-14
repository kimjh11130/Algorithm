#include <stdio.h>

typedef struct element {
    int x, y;
} element;

int poow(int i) { return i * i; }

int min(int a, int b) { return a > b ? a : b; }

int max(int a, int b) { return a < b ? a : b; }

int main(void) {
    int n, arr[1001][1001] = {0}, cnt = 0, a, b, c, d;
    element p, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 5) p.x = i, p.y = j;
            else if (arr[i][j] == 2) s.x = i, s.y = j;
        }
    }
    a = min(p.x, s.x), b = max(p.x, s.x), c = min(p.y, s.y), d = max(p.y, s.y);
    if (poow(b - a) + poow(d - c) < 25) {
        printf("0");
        return 0;
    }
    for (int i = b; i <= a; i++) {
        for (int j = d; j <= c; j++) {
            if (arr[i][j] == 1) cnt++;
        }
    }
    printf("%d", cnt > 2 ? 1 : 0);
}