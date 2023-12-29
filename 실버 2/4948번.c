#include <stdio.h>

int main() {
    int arr[246913] = {1, 1}, a, cnt;
    for (int i = 2; i < 500; i++) {
        if (arr[i] == 0) {
            for (int j = i * 2; j < 246913; j += i) {
                arr[j] = 1;
            }
        }
    }
    scanf("%d", &a);
    while (a != 0) {
        cnt = 0;
        for (int i = a + 1; i <= 2 * a; i++) {
            if (arr[i] == 0) cnt++;
        }
        printf("%d\n", cnt);
        scanf("%d", &a);
    }
}