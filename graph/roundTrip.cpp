#include <bits/stdc++.h>
using namespace std;


/**
 * @brief So in this version we are using bfs. There is a fundamental difference between how dfs and bfs process the cycles. In BFS we can have cases like 1-2-3-6
 *                                         |-8-9-|
 * So the entry point in this connected component was lets say 1, but how bfs process its possible that we see edge 6-9 but problem is when you see this edge for the second time the node 6 might still be in queue, so we need to backtrack from 9 back to 1 and 6 back to 1, basically from both the nodes we back track back to entry point of connected component and join it.
 * One special case we need to deal with is , where entry point of the connected component is not the entry point of the cycle, So wee need to check that.
 * * 1 - 2 - 3
 * *     |   |
 * *     - 4 -
 */
inline void construct (int node, vector<int>& res, vector<int>& parent) {
    while (node != -1) {
        res.push_back(node);
        node = parent[node];
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> parent(n+1, 0);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": [ ";
    //     for (int j: graph[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << "]\n";
    // }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (parent[i]==0) {
            parent[i] = -1;
            q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            // cout << "Proccesing : " << curr << endl;
            for (int& nhbr: graph[curr]) {
                if (nhbr==parent[curr]) {
                    continue;
                }
                if (parent[nhbr]!=0) {
                    vector<int> res = {};
                    construct(curr, res, parent);
                    reverse(res.begin(), res.end());
                    construct(nhbr, res, parent);
                    
                    // To deal with cases like
                    /**
                     * 1 - 2 - 3
                     *     |   |
                     *     - 4 -
                     * Basically entry point of the connected component is kind of a tail of cycle   
                     */
                    int i = 0, j = res.size();
                    j--;
                    for (; i < j && res[i]==res[j]; i++, j--);
                    if (i!=0) {
                        i--;
                        j++;
                    }
                    cout << j-i+1 << "\n";
                    for (;i <= j; i++) {
                        cout << res[i] << ' ';
                    }
                    // cout << res.size() << endl;
                    // for (int& node: res) {
                    //     cout << node << ' ';
                    // }
                    cout << "\n";
                    return 0;
                }
 
                parent[nhbr]=curr;
                q.push(nhbr);
            }
        }
    }
 
    cout << "IMPOSSIBLE\n";
    return 0;
}
