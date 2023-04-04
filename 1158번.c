#include <stdio.h>

int queue[25000000], f = 0, r = 0;

int main() {
    int k;
    scanf("%d %d", &r, &k);
    for (int i = 0; i < r; ++i) {
        queue[i] = i + 1;
    }
    printf("<");
    while(r - f != 1) {
        while (f % k == k - 1 && r - f != 1) {
            printf("%d, ", queue[f++]);
        }
        queue[r++] = queue[f++];
    }
    printf("%d>", queue[f]);
}