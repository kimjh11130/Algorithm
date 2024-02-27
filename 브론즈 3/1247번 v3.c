#include <stdio.h>

#define MAX 9223372036854775807

typedef long long int ll;

int main() {
    for (int i = 0; i < 3; i++) {
        char c;
        ll res = 0, over = 0, n, a;
        scanf("%lld", &n);
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a);
            if (MAX - res <= a) res += a - MAX, over++;
            else if (res + a < 0) res += a + MAX, over--;
            else res += a;
        }
        if(over < 0) c = '-';
        else if(over || res) c = '+';
        else c = '0';
        printf("%c\n", c);
    }
}