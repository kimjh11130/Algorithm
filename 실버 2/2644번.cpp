#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b, m, x, y;
    cin >> n >> a >> b >> m;
    queue<int> que;
    vector<int> vis(n, 0);
    vector<vector<int>> graph(101);
    while (m--) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    que.push(a);
    while (!que.empty()){
        x = que.front(), que.pop();
        if(x == b){
            cout << vis[b];
            return 0;
        }
        for(auto i: graph[x]){
            if(!vis[i]) que.push(i), vis[i] = vis[x] + 1;
        }
    }
    cout << -1;
}
