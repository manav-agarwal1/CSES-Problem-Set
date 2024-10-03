#include <bits/stdc++.h>
using namespace std;
int EOC = -1;
int travel (vector<vector<int>>& graph, vector<int>& visited, vector<int>& res, int node) {
    if (visited[node] != -1) {
        return 0;
    }
    visited[node] = 1;
    for (int& nhbr: graph[node]) {
        if (visited[nhbr]==-1) {
            int state = travel(graph, visited, res, nhbr);
            if (state != 0) {
                // if state is 0 then we found it but in some other path no in current one
                if (state == 2) {
                    // no need to add
                    // cycle found
                    return state;
                }
                res.push_back(node);
                if (node == EOC) {
                    // processed whole
                    return 2;
                }
                return 1;
            }
        }
        else if (visited[nhbr]==1) {
            res.push_back(nhbr);
            res.push_back(node);
            EOC = nhbr;
            return 1; // need to add
        }
    }
    visited[node]=2;
    return 0;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1, -1);
    vector<int> res;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]==-1) {
            travel(graph, visited, res, i);
        }
        if (EOC!=-1) {
            break;
        }
    }
    if (EOC==-1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        reverse(res.begin(), res.end()); // IMPO is a directed graph
        cout << res.size() << "\n";
        for (auto& it: res) {
            cout << it << ' ';
        }
        cout << "\n";
    }
    return 0;

}