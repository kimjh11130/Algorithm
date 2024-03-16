#include <stdio.h>

int main(void) {
    int x, i = 1;
    for (scanf("%d", &x); i < x;) x -= i++;
    if (i % 2)printf("%d/%d", i - x + 1, x);
    else printf("%d/%d", x, i - x + 1);
}