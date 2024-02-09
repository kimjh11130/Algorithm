#include <stdio.h>

int main() {
    int n, k;
    short arr[1001] = {0};
    scanf("%d %d", &n, &k);
    for (int i = 2; i <= n; i++) {
        if (!arr[i]) {
            for (int j = i; j <= n; j += i) {
                if (!arr[j]) --k, arr[j] = 1;
                if (!k){
                    printf("%d", j);
                    return 0;
                }
            }
        }
    }
}