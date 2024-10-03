#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Prims
 * 
 * @return int 
 */
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int64_t, int64_t>>> graph(n+1);
    vector<bool> visited(n+1, false);
    priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> pq;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    pq.push({0ll, 1});
    int tree = 0;
    int64_t res = 0ll;
    while (tree < n && !pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        if (visited[curr.second]) {
            continue;
        }
        visited[curr.second] = true;
        tree++;
        res += curr.first;
        for (auto& nhbr: graph[curr.second]) {
            if (!visited[nhbr.first]) {
                pq.push({nhbr.second, nhbr.first});
            }
        }
    }
    if (tree != n) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << res << "\n";
    }
    return 0;
}