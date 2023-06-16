#include <stdio.h>

int main(void){
    int n, m, arr[301][301] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
            if(i == 0 && j != 0){
                arr[i][j] += arr[i][j-1];
            }else if(j == 0 && i != 0){
                arr[i][j] += arr[i-1][j];
            }else if(i != 0){
                arr[i][j] += arr[i-1][j] > arr[i][j-1] ? arr[i-1][j] : arr[i][j-1];
            }
        }
    }
    printf("%d", arr[n-1][m-1]);
}