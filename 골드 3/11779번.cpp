#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 2e9

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, fr, to, go, a, b, tmp, t;
    cin >> n >> m;
    vector<int> route(n + 1, 0), res, dist(n + 1, MAX);
    vector<pair<int, int>> graph[n + 1];
    priority_queue<pair<int, int>> que;
    while (m--) {
        cin >> fr >> to >> go;
        graph[fr].emplace_back(to, go);
    }
    cin >> a >> b;
    que.emplace(0, a), dist[a] = 0;
    while (!que.empty()) {
        auto [d, x] = que.top();
        que.pop(), d = -d;
        if(x == b){
            tmp = b, res.push_back(b);
            break;
        }
        if (dist[x] < d) continue;
        for (auto [next, len]: graph[x]) {
            if (dist[next] > d + len) {
                route[next] = x, dist[next] = d + len, que.emplace(-d - len, next);
            }
        }
    }
    while (tmp != a) {
        t = route[tmp], res.push_back(t), tmp = t;
    }
    reverse(res.begin(), res.end());
    cout << dist[b] << "\n" << res.size() << "\n";
    for (int i: res) cout << i << ' ';
}