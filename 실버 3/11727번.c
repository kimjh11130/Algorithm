#include <stdio.h>

int main(void) {
    int n, arr[1001] ={0,1, 3};
    scanf("%d", &n);
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 2] * 2 + arr[i - 1]) % 10007;
    }
    printf("%d", arr[n]);
}