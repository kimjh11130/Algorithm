#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, fr, to, go;
    ll min = 1e15;
    cin >> n >> m >> k;
    vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, 1e15));
    vector<pair<int, int>> graph[n + 1];
    priority_queue<tuple<ll, int, int>> que;
    while (m--) {
        cin >> fr >> to >> go;
        graph[fr].emplace_back(to, go);
        graph[to].emplace_back(fr, go);
    }
    que.emplace(0,1,0), dist[n][0] = 0;
    while (!que.empty()) {
        auto [d, x, z] = que.top();
        que.pop(), d = -d;
        if (x == n) min = min > d ? d : min;
        if (dist[x][z] < d) continue;
        for (auto [next, ran]: graph[x]) {
            if (z + 1 <= k && dist[next][z + 1] > d) {
                dist[next][z + 1] = d, que.emplace(-d, next, z + 1);
            }
            if (dist[next][z] > ran + d) {
                dist[next][z] = ran + d, que.emplace(-ran - d, next, z);
            }
        }
    }
    cout << min;
}