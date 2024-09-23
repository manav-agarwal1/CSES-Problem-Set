#include <bits/stdc++.h>
using namespace std;
// since we need to look at all the paths we can do bfs or dfs anything
// It can go exponential in worst case for DFS

void travel (vector<vector<pair<int64_t, int64_t>>>& graph, vector<bool>& visited, int node, int64_t path_max, int64_t path_cost, int64_t& res) {
    if (node+1==(int)graph.size()) {
        // 
        path_cost -= path_max;
        path_max /= 2;
        path_cost += path_max;
        res = min(res, path_cost);
        return;
    }

    visited[node] = true;
    for (auto& nhbr: graph[node]) {
        if (!visited[nhbr.first]) {
            travel(graph, visited, nhbr.first, max(path_max, nhbr.second), path_cost+nhbr.second, res);
        }
    }
	visited[node] = false;
    // In my current path i dont want node to repeat as they will increase cost but in other path they can come in some other order
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int64_t, int64_t>>> graph(n+1);
    vector<bool> visited(n+1, false);
    int64_t res = LLONG_MAX;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    travel(graph, visited, 1, LLONG_MIN, 0ll, res);
    cout << res << "\n";
    return 0;
}