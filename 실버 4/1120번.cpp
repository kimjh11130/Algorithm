#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int max = 99, cnt;
    char a[51], b[51];
    cin >> a >> b;
    for (int i = 0; i <= strlen(b) - strlen(a); i++) {
        cnt = 0;
        for (int j = 0; j < strlen(a); j++) {
            if (a[j] != b[i + j]) cnt++;
        }
        max = max > cnt ? cnt : max;
    }
    cout << max;
}
