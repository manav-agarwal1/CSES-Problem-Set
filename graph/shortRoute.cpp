#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int64_t, int64_t>>> graph(n+1);
    vector<int64_t> res(n+1, LLONG_MAX);
    vector<bool> visited(n+1, false);
    priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> pq;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    pq.push({0ll, 1});
    res[1] = 0ll;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (auto& nhbr: graph[u]) {
            int v = nhbr.first;
            int w = nhbr.second;
            if (res[v] > res[u] + w) {
                res[v] = res[u] + w;
                pq.push({res[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << "\n";
    return 0;
}