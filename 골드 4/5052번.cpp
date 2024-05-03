#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check() {
    int n;
    string a;
    vector<string> arr;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a, arr.push_back(a);
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1].substr(0, arr[i].length())) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cout << (check() ? "YES\n" : "NO\n");
    }
    return 0;
}
