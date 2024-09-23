#include <bits/stdc++.h>
using namespace std;
const long long inf = LLONG_MAX;
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> graph(n+1, vector<long long>(n+1, inf));
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = min(graph[u][v], w+0ll); //  test case have multiple edges between same end points
    }
    // Order of the loops is critical
    for (int through = 1; through <= n; through++) {
        for (int src = 1; src <= n; src++) {
            for (int dst = 1; dst <= n; dst++) {
                if (graph[src][through] != inf && graph[through][dst] != inf) {
                    graph[src][dst] = min(graph[src][dst], graph[src][through] + graph[through][dst]);
                } 
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << graph[i][j] << ", ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0, u, v; i < q; i++) {
        cin >> u >> v;
        cout << ((graph[u][v]==inf) ? -1 : graph[u][v]) << "\n";
    }
    return 0;
}