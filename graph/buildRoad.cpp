#include <bits/stdc++.h>
using namespace std;

void travel (vector<vector<int>>& graph, vector<bool>& visited, int city) {
    visited[city] = true;
    for (int& nhbr: graph[city]) {
        if (!visited[nhbr]) {
            travel(graph, visited, nhbr);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<pair<int, int>> roads;
    for (int i = 1, prev = -1; i <= n; i++) {
        if (!visited[i]) {
            travel(graph, visited, i);
            if (prev!=-1) {
                roads.push_back({prev, i});
            }
            prev = i;
        }
    }
    cout << roads.size() << "\n";
    for (auto& it: roads) {
        cout << it.first << ' ' << it.second << "\n";
    }
    return 0;
}