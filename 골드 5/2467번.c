#include <stdio.h>

int abs(int a) { return a > 0 ? a : -a; }

int main() {
    int r, arr[100001], f = 0, min = 1e9, max = 1e9;
    scanf("%d", &r), --r;
    for (int i = 0; i <= r; i++) {
        scanf("%d", &arr[i]);
    }
    while (f < r) {
        int fir = arr[f], las = arr[r];
        if (abs(min + max) > abs(fir + las)) min = fir, max = las;
        if (fir + las > 0) --r;
        else ++f;
    }
    printf("%d %d", min, max);
}
