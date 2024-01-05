#include <stdio.h>

typedef long long int ll;

ll m, n, s, r = 0, mod = 1e9 + 7;

ll pow(ll a, ll b) {
    long long int res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res % mod;
}

int main(void) {
    scanf("%lld", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld", &n, &s);
        r = (r + s * pow(n, mod - 2)) % mod;
    }
    printf("%lld", r);
}