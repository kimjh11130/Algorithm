#include <stdio.h>

int main(void){
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {

        char memo[100000] = {0};
        char copy[100000] = {0};
        int differece = 0, first = 0, second = 0, result = 0, t = 0;
        scanf("%d", &a);
        scanf("%s", memo);
        scanf("%s", copy);
        for (int j = 0; j < a; j++) {
            if (memo[j] != copy[j]) {
                t++;
            }
            if (memo[j] == 'B') {
                first++;
            }
            if (copy[j] == 'B') {
                second++;
            }
        }
        differece = (first -second) > 0 ? first - second : second - first;
        result = differece + (t - differece) / 2;
        printf("%d\n", result);
    }
}