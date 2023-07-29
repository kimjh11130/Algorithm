#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int n, arr[1000001] = {0, 0, 1};
    scanf("%d", &n);
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 0){
            if(i % 3 == 0){
                arr[i] = min(arr[i-1],min(arr[i/2], arr[i/3])) + 1;
            } else {
                arr[i] = min(arr[i-1], arr[i/2]) + 1;
            }
        } else {
            if(i % 3 == 0){
                arr[i] = min(arr[i-1], arr[i/3]) + 1;
            } else {
                arr[i] = arr[i-1] + 1;
            }
        }
    }
    printf("%d", arr[n]);
}