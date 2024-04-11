#include <iostream>
#include <queue>
#include <vector>

#define INF 2e9

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, e, fr, to, va, a, b;
    cin >> n >> e;
    vector<int> dist(n + 1, INF);
    vector<pair<int, int>> graph[n + 1];
    priority_queue<pair<int, int>> que;
    que.emplace(0, a), dist[a] = 0;
    while (e--) {
        cin >> fr >> to >> va;
        graph[fr].emplace_back(to, va);
    }
    cin >> a >> b, que.emplace(0, a), dist[a] = 0;
    while (!que.empty()) {
        auto [d, x] = que.top();
        que.pop(), d = -d;
        if (dist[x] < d) continue;
        for (auto [next, ran]: graph[x]) {
            if (dist[next] > d + ran) {
                que.emplace(-d - ran, next), dist[next] = ran + d;
            }
        }
    }
    cout << dist[b];
}