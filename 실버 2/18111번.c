#include <stdio.h>

int main(void) {
    int n, m, b, arr[500][500] = {0}, max = 0, min = 256, result = 1000000000, ss;
    scanf("%d %d %d", &n, &m, &b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            max = max > arr[i][j] ? max : arr[i][j];
            min = min > arr[i][j] ? arr[i][j] : min;
        }
    }
    for (int i = min; i <= max; i++) {
        int a = 0, tmp = b;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[j][k] > i) {
                    tmp += arr[j][k] - i;
                    a += (arr[j][k] - i) * 2;
                } else {
                    tmp -= i - arr[j][k];
                    a += i - arr[j][k];
                }
            }
        }
        if (tmp < 0) break;
        else if (result >= a){
            result = a;
            ss = i;
        }
    }
    printf("%d %d", result, ss);
}