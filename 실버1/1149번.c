#include <stdio.h>

int main(void) {
    int n, arr[1001][3], min = 1000000000;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            switch (j) {
                case 0:{
                    arr[i][0] += arr[i-1][1] < arr[i-1][2] ? arr[i-1][1] : arr[i-1][2];
                    break;
                }case 1:{
                    arr[i][1] += arr[i-1][0] < arr[i-1][2] ? arr[i-1][0] : arr[i-1][2];
                    break;
                }case 2:{
                    arr[i][2] += arr[i-1][0] < arr[i-1][1] ? arr[i-1][0] : arr[i-1][1];
                    break;
                }
                default:
                    break;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        min = min > arr[n-1][i] ? arr[n-1][i] : min;
    }
    printf("%d", min);
}