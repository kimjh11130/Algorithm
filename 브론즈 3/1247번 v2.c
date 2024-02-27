#include <stdio.h>
#include <stdlib.h>

#define MAX 9223372036854775807

typedef long long int ll;

int n;
ll arr[100001] = {0};

int comp(const void *a, const void *b) {
    return *(ll *) a > *(ll *) b ? -1 : *(ll *) a == *(ll *) b ? 0 : 1;
}

char solve(){
    ll res = 0, over = 0;
    for (int j = 0; j < n; j++) {
        if (MAX - res <= arr[j]) res += arr[j] - MAX, over++;
        else if (res + arr[j] < 0) res += arr[j] + MAX, over--;
        else res += arr[j];
        if(over < 0) return '-';
    }
    return over || res ? '+' : '0';
}

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%lld", &arr[j]);
        }
        qsort(arr, n, sizeof(ll), comp);
        printf("%c\n", solve());
    }
}