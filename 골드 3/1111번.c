#include <stdio.h>

int main() {
    int n, arr[51], a, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    if (n == 1) printf("A");
    else if (n == 2) {
        if (arr[0] == arr[1]) printf("%d", arr[0]);
        else printf("A");
    } else {
        if (arr[1] - arr[0] == 0) a = 0;
        else a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
        for (int i = 2; i <= n; i++) {
            tmp = (arr[i - 1] - arr[i - 2]) * a + arr[i - 1];
            if (i == n)printf("%d", tmp);
            else if (arr[i] != tmp) {
                printf("B");
                break;
            }
        }
    }
}
