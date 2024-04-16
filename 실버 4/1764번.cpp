#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a;
    string s;
    vector<string> res;
    map<string, short> map;
    cin >> n >> a;
    while (n--) cin >> s, map[s] = 1;
    while (a--) {
        cin >> s;
        if (map.find(s) != map.end()) res.push_back(s);
    }
    std::sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (auto i: res) {
        cout << i << "\n";
    }
}