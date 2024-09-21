#include <bits/stdc++.h>
using namespace std;

int EOC = -1; // end of cycle
int travel (vector<vector<int>>& graph, vector<int>& visited, vector<int>& res, int node, int parent) {
    if (visited[node] != -1) {
        // 1 - 2 - 3 - 5 - 1, so basically we have arrived at 1, now we backtrack from 5
        // we have a cycle and now construction will begin
        res.push_back(node);
        EOC = node;
        return 1; // unders construction
    }

    visited[node] = 1; // No nhbr processed so far
    for (int& nhbr: graph[node]) {
        if (nhbr==parent) {
            continue;
        }
        int state = travel (graph, visited, res, nhbr, node);
        if (state == 1) {
            // cycle under construction
            res.push_back(node);
            if (EOC == node) {
                // while backtracking if I again reach to EOC then i stop
                return 2;
            }
            return 1;
        }
        else if (state == 2) {
            return 2; // this will ensure after cycle retrieval we dont process anything unecessary
        }
    }
    visited[node] = 2; // all nhbr processed
    return 0;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1, -1);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (visited[i]==-1 && res.size()==0) {
            travel(graph, visited, res, i, -1);
        }
    }
    if (res.size() != 0) {
        cout << res.size() << "\n";
        for (int& node: res) {
            cout << node << ' ';
        }
        cout << "\n";
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}