#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * If any vertex say x can be reached by all others and x can reach all others then we can say the answer is YES
 * For the second check we can run dfs as first case in reverse graph
 * @return int 
 */
void travel (vector<vector<int>>& graph, vector<bool>& visited, int curr) {
    // cout << curr << " -> ";
    visited[curr] = true;
    for (int& nhbr: graph[curr]) {
        if (!visited[nhbr]) {
            travel(graph, visited, nhbr);
        }
    }
}
bool check(vector<bool>& visited, int cnt) {
    for (int i = 1; i < (int)visited.size(); i++) {
        if (!visited[i]) {
            cout << "NO\n";
            if (cnt == 1) {
                cout << 1 << ' ' << i << "\n";
            }
            else {
                cout << i << ' ' << 1 << "\n";
            }
            return false;
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<vector<int>> revGraph(n+1);
    vector<bool> visited(n+1, false);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);
    }
    travel(graph, visited, 1);
    // cout << "\n";
    bool flag = check(visited, 1);
    if (flag) {
        fill(visited.begin(), visited.end(), false);
        travel(revGraph, visited, 1);
        // cout << "\n";
        flag = check(visited, 2);
    }
    if (flag) {
        cout << "YES\n";
    }
    return 0;

}