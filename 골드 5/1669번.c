#include <stdio.h>

int main(void) {
    int first, last, height, i;
    scanf("%d %d", &first, &last);
    height = last - first;
    for (i = 1; height > 0; i++) {
        if (i % 2 == 1) {
            height -= (i + 1) / 2;
        } else {
            height -= i / 2;
        }
    }
    printf("%d\n", i-1);
}