#include <iostream>

using namespace std;

int n, k, cnt;

void back(int a, const string &str) {
    if (cnt == k) return;
    if (n <= a) {
        if (a == n) {
            ++cnt;
            if (cnt == k) cout << str;
        }
        return;
    }
    back(a + 1, str + "+1");
    back(a + 2, str + "+2");
    back(a + 3, str + "+3");
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    back(1, "1"), back(2, "2"), back(3, "3");
    if(cnt < k) cout << "-1";
}