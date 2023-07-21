#include <stdio.h>

int n, arr[11] = {0}, i;

int check(int num){
    int cnt = -1, tmp;
    if (num == 0 && arr[0] == 0) {
        return i + 1;
    }
    while (num > 0) {
        cnt++;
        num /= 10;
        tmp = num % 10;
        if (arr[tmp]) {
            break;
        }
    }
    if (!num && cnt != -1) {
        return cnt + i > (n - 100 > 0 ? n - 100 : 100 - n) ? (n - 100 > 0 ? n - 100 : 100 - n) : cnt + i;
    } else {
        return -1;
    }
}

int main(void) {
    int a, m, as = 100000000, sa = 100000000;
    scanf("%d", &n);
    scanf("%d", &m);
    for (i = 0; i < m; ++i) {
        scanf("%d", &a);
        arr[a] = 1;
    }

    if (n == 100) {
        printf("0");
        return 0;
    } else if (m == 10) {
        printf("%d", n - 100 > 0 ? n - 100 : 100 - n);

        return 0;
    } else if (n == 0) {
        for (int j = 0; j < 10; j++) {
            if(!arr[j]){
                printf("%d", j + 1);
                return 0;
            }
        }
    }
    for (i = 0; i <= 10000001; i++) {
        m = n - i;
        if (m == 100) {
            as = i;
            break;
        }
        if(check(m * 10) >= 0) {
            as = check(m * 10);
            break;
        }
    }
    for (i = 0; i <= 1000000; i++) {
        a = n + i;
        if (a == 100) {
            sa = i;
            break;
        }
        if(check(a * 10) >= 0) {
            sa = check(a * 10);
            break;
        }
    }
    printf("%d", as > sa ? sa : as);
}