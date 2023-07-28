#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, arr[1001] = {0}, count = 0, prev;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &prev);
        arr[i] = arr[i] - prev;
    }
    prev = arr[0];
    for (int i = 1; i < n; ++i) {
        if(arr[i] > 0) {
            if (prev < 0) {
                count += abs(prev);
            } else if(prev >= arr[i]){
                count += prev - arr[i];
            }
        } else {
            if(prev > 0){
                count += prev;
            } else if(prev <= arr[i]){
                count += abs(prev) + arr[i];
            }
        }
        prev = arr[i];
    }
    count += abs(prev);
    printf("%d", count);
}