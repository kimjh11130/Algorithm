#include <stdio.h>

typedef long long int ll;

ll P, A;

ll pow(ll a, ll b) {
    ll res = 1, mod = b;
    while (b != 0) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int isPrime(long long int a) {
    int i;
    for (i = 2; i * i <= a; i++) {
        if (!(a % i)) return 0;
    }
    return 1;
}

int main(void) {
    scanf("%lld %lld", &P, &A);
    while (A + P != 0) {
        printf("%s\n", pow(A, P) == A && !isPrime(P) ? "yes" : "no");
        scanf("%lld %lld", &P, &A);
    }
}