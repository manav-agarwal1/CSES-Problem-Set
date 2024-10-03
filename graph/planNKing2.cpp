#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * Tarjan Algo
 * @return int 
 */
int ti = 0;
int comp = 1;
void travel (vector<vector<int>>& graph, vector<bool>& visited, vector<int>& discover, vector<int>& lowLink, vector<int>& res, stack<int>& st, int curr) {
    discover[curr] = lowLink[curr] = ++ti;
    st.push(curr);
    visited[curr] = true; // in stack
    // cout << curr << " -> ";
    for (int& nhbr: graph[curr]) {
        if (discover[nhbr] == -1) {
            travel(graph, visited, discover, lowLink, res, st, nhbr);
            lowLink[curr] = min(lowLink[curr], lowLink[nhbr]);
        } else if (visited[nhbr]) {
            lowLink[curr] = min(lowLink[curr], lowLink[nhbr]);
        }
    }

    if (lowLink[curr] == discover[curr]) {
        while (st.top() != curr) {
            visited[st.top()] = false;
            lowLink[st.top()] = lowLink[curr];
            res[st.top()] = comp;
            st.pop();
        }
        // for curr
        visited[st.top()] = false;
        lowLink[st.top()] = lowLink[curr];
        res[st.top()] = comp;
        st.pop();
        comp++;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<vector<int>> revGraph(n+1);
    vector<bool> visited(n+1, false);
    vector<int> discover(n+1, -1);
    vector<int> lowLink(n+1, INT_MAX);
    vector<int> res(n+1, -1);
    stack<int> st;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);
    }
    // dfs 1
    for (int i = 1; i <= n; i++) {
        if (discover[i] == -1) {
            travel(graph, visited, discover, lowLink, res, st, i);
        }
    }
    cout << comp-1 << "\n";
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << "\n";
    return 0;
}