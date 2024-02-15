#include <stdio.h>

int min(int a, int b) {
    return !a || a > b ? b : a;
}

int main() {
    int n, a;
    short arr[1000001] = {0};
    for (int i = 1; i * i <= 1000000; i++) {
        arr[i * i] = 1;
    }
    for (int i = 1; i <= 1000000; i++) {
        if (!arr[i]) {
            for (int j = 1; j * j + i <= 1000000; j++) {
                arr[i + j * j] = 1;
            }
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        printf("%s\n", arr[a] ? "koosaga" : "cubelover");
    }
}