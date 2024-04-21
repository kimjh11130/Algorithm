#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, res = 2e9, max = 0, tmp;
    priority_queue<int, vector<int>, greater<>> que;
    cin >> n;
    while (n--) {
        cin >> a, que.push(a);
        max = max > a ? max : a, tmp = max;
    }
    while (n <= max) {
        if (res > tmp - n) res = tmp - n;
        if (n != -1)que.push(n * 2);
        tmp = tmp > n * 2 ? tmp : n * 2, n = que.top(), que.pop();
    }
    cout << res;
}