#include <stdio.h>

int main() {
    int k, n, arr[10001] = {0}, max = 0;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }
    long long int s = 1, e = max, result = 0;
    while (s <= e) {
        long long int mid = (s + e) / 2, cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += arr[i] / mid;
        }
        if (cnt >= n) {
            s = mid + 1;
            result = mid;
        } else {
            e = mid - 1;
        }
    }
    printf("%lld", result);
}