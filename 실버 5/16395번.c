#include <stdio.h>

int main(void){
    int n, k, arr[31][31] = {0}, a;
    arr[0][0] = 1;
    arr[1][0] = 1;
    scanf("%d %d", &n, &k);
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < i/2+1; j++) {
            arr[i][j] = arr[i-1][j] ? arr[i-1][j] + arr[i-1][j-1] : arr[i-1][j-1] * 2;
        }
    }
    printf("%d", arr[n-1][(k > (n+1)/2 ? n - k : k - 1)]);
}