#include <stdio.h>

int main(void){
    int n,x,y;
    int arr[15][15]={0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        for (int j = 0; j <= x; ++j) {
            for (int k = 0; k <= y; ++k) {
                arr[j][0] = 1;
                arr[0][k] = k + 1;
            }
        }
        for (int j = 1; j <= x; ++j) {
            for (int k = 1; k <= y; ++k) {
                arr[j][k] = arr[j-1][k] + arr[j][k-1];
            }
        }
        printf("%d\n", arr[x][y-1]);
    }
}