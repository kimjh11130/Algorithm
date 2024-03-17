#include <stdio.h>

typedef long long int ll;

ll n, m, t, f;

void count(ll num, int flag) {
    for (ll i = 2; i <= num; i *= 2) t += flag ? -(num / i) : num / i;
    for (ll i = 5; i <= num; i *= 5) f += flag ? -(num / i) : num / i;
}

int main(void) {
    scanf("%lld %lld", &n, &m);
    count(n, 0), count(n - m, 1), count(m, 1);
    printf("%lld", t > f ? f : t);
}