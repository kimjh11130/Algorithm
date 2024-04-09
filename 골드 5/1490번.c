#include <stdio.h>

typedef long long int ll;

ll f(ll a, ll b) { return a % b ? f(b, a % b) : b; }

ll s(ll a, ll b) { return a * b / f(a, b); }

int main() {
    ll n, r = 0, f = -1, que[40000], all = 1;
    scanf("%lld", &n), que[r] = n;
    while (n) {
        if (n % 10) all = s(all, n % 10);
        n /= 10;
    }
    while (f < r) {
        ll x = que[++f];
        if (x % all == 0) {
            printf("%lld", x);
            return 0;
        }
        for (int i = 0; i < 10; i++) que[++r] = x * 10 + i;
    }
}
