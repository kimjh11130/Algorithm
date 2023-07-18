#include <stdio.h>

int main(void){
    int n, arr[200001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = n-1; i >= 0; i--) {
        if(arr[i]){
            if(i+arr[i] > n){
                arr[i] = 1;
            } else if(arr[i + arr[i]+1] == 0){
                arr[i] = 1;
            } else {
                arr[i] = arr[i+arr[i]+1]+1;
            }
        } else{
            arr[i] = arr[i+1] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}