#include <stdio.h>

int main(void){
    int t, n, arr[2][100001] = {0};
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &arr[j][k]);
            }
        }
        arr[0][1] += arr[1][0];
        arr[1][1] += arr[0][0];
        for (int j = 2; j < n; j++) {
            arr[0][j] += arr[1][j-1] > arr[1][j-2] ? arr[1][j-1] : arr[1][j-2];
            arr[1][j] += arr[0][j-1] > arr[0][j-2] ? arr[0][j-1] : arr[0][j-2];
        }
        printf("%d\n", arr[0][n-1] > arr[1][n-1] ? arr[0][n-1] : arr[1][n-1]);
    }
}