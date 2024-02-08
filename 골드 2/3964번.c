#include <stdio.h>

typedef unsigned long long int ll;

short ch[1000000];
int sosu[78500], MAX;
ll dsu[1000][2];

void makeSosu() {
    int index = 0;
    for (int i = 2; i < 1000000; i++) {
        if (!ch[i]) {
            sosu[index++] = i;
            for (int j = i + i; j < 1000000; j += i) {
                ch[j] = 1;
            }
        }
    }
    MAX = index;
}

ll divide(ll n) {
    ll a = 2, cnt = 0, i = 0, index = 0;
    for (int j = 0; j < 1000; j++) dsu[j][0] = 0, dsu[j][1] = 0;
    while (n - 1 && index < MAX) {
        if (n % a == 0) ++cnt, n /= a;
        else if (cnt)  dsu[i][0] = a, dsu[i++][1] = cnt, cnt = 0;
        else a = sosu[++index];
    }
    if (cnt) dsu[i][0] = a, dsu[i++][1] = cnt;
    if (n != 1) dsu[i][0] = n, dsu[i++][1] = 1;
    return i;
}

int main() {
    int t;
    makeSosu();
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        ll n, k, all, res;
        scanf("%llu %llu", &n, &k);
        all = divide(k);
        for (int j = 0; j < all; j++) {
            ll a = 1, tmp = 0;
            while (a <= n / dsu[j][0]) {
                a *= dsu[j][0];
                tmp += n / a;
            }
            tmp /= dsu[j][1];
            if (!j || tmp < res) res = tmp;
        }
        printf("%llu\n", res);
    }
}