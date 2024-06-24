#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s;
    long long int sum = 0;
    cin >> s;
    sort(s.begin(), s.end(),greater<>());
    for (auto o : s) sum += o-'0';
    if (s[s.length() - 1] != '0' || sum % 3 ) cout << -1;
    else cout << s;
}