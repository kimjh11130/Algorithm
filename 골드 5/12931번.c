#include <stdio.h>

int main() {
    int n, b[51] = {0}, all = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        all += b[i];
    }
    while (all != 0){
        for (int i = 0; i < n; ++i) {
            if(b[i] % 2){
                b[i] -= 1;
                all -= 1;
                cnt++;
            }
        }
        if(!all) break;
        for (int i = 0; i < n; ++i) {
            b[i] /= 2;
        }
        all /= 2;
        cnt++;
    }
    printf("%d", cnt);
}