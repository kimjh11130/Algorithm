#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare1(pair<int, int> a, pair<int, int> b) {
    return b.second == a.second ? b.first > a.first : b.second > a.second;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b, cnt = 1, i;
    vector<pair<int, int>> arr;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a >> b;
        arr.emplace_back(a, b);
    }
    sort(arr.begin(), arr.end(), compare1);
    a = 0, i = 0;
    while (a == i) {
        for (i = a + 1; i < n; i++) {
            if (arr[i].first >= arr[a].second) {
                a = i, cnt++;
                break;
            }
        }
    }
    cout << cnt;
}
