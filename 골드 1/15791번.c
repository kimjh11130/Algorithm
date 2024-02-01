#include <stdio.h>

typedef long long int ll;

ll n, m, mod = 1e9 + 7, nf = 1, mf = 1, nmf = 1;

ll pow(ll a, ll b) {
    ll res = 1;
    while (b != 0) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main(void) {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        nf = nf * i % mod;
        if (i == m) mf = nf;
        if (i == n - m) nmf = nf;
    }
    printf("%lld", nf * pow(mf * nmf % mod, mod - 2) % mod);
}