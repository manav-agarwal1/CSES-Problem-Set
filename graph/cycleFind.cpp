#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
// we need to use bellman ford as negative cycle can have any edges
//  any other algo with be ran n times to get the answer in worse case
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int64_t>> edges; // we may have disconnected componenrts in that case this will help to run algo better
    vector<int64_t> dist(n+1, inf); // actually you can initialize to anything and it would work as you just need to check whether it goes down after the nth iteration
    vector<int64_t> parent(n+1, -1);
    // Even we are starting everything at infinity but since we want for negative edges so we are fine it will still give negative cycles
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int EOC = -1;
    for (int i = 1, u, v, w; i <= n; i++) {
        // run n times instead n-1
        for (auto& edge: edges) {
            u = edge[0];
            v = edge[1];
            w = edge[2];
            if (dist[u] + w < dist[v]) {
                //  it will only work for negative cycles
                if (i==n) {
                    EOC = v;
                }
                parent[v] = u;
                dist[v] = dist[u] + w;
            }
        }
    }
    if (EOC == -1) {
        cout << "NO\n";
    }
    else {
        // we might not be on a cycle so parents wont be updated
        // in our given case
        /**
         * 4 5
            1 2 1
            2 4 1
            3 1 1
            4 1 -3
            4 3 -2
        we will end at 3 but it is not part of cycle its some vertext that you processed without knowing the order so we need to backtrack atleast n times ie; all vertex to ensure we enter the cycle
        in our case its simply the parent but as we have no control over the order of edges so it wont be the case always
         */
        for (int i = 0; i < n; i++) {
            EOC = parent[EOC];
        }
        vector<int64_t> cycle;
        int64_t ed = EOC;
        do {
            cycle.push_back(EOC);
            EOC = parent[EOC];
        } while (EOC != ed);
        cycle.push_back(EOC);
        // since its a directed graph, reverse cycle
        // DONT FORGET!!! Made boo boo while first submit :)
        reverse(cycle.begin(), cycle.end());
        cout << "YES\n";
        for (int64_t& it: cycle) {
            cout << it << ' ';
        }
        cout << "\n";

    }
    return 0;
}