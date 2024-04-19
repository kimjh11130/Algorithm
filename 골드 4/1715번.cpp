#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, t, cnt = 0;
    priority_queue<int> que;
    cin >> n;
    while (n--) cin >> t, que.push(-t);
    while (que.size() != 1) {
        n = -que.top(), que.pop(), t = -que.top(), que.pop();
        cnt += n + t, que.push(-n - t);
    }
    cout << cnt;
}