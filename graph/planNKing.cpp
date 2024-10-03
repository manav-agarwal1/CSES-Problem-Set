#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * Kosaraju Algo: dfs and process nodes in stack, then in order of stack do dfs on reverse graph and whatever you hit is the SCC
 * 
 * https://www.youtube.com/watch?v=9Wbej7Fy5Lw
 * @return int 
 */
class KosarajuSolver {
    private:
        const vector<vector<int>> graph;
        vector<vector<int>> rev_graph;
        stack<int> st;
        vector<bool> visited;
        vector<int> res;
        int comp = 1;
        void travel (int curr) {
            for (const int& nhbr: graph[curr]) {
                if (!visited[nhbr]) {
                    visited[nhbr] = true;
                    travel(nhbr);
                
                }
            }
            st.push(curr);
        }
    public:
        KosarajuSolver (const vector<vector<int>>& graph) : graph(graph), rev_graph(graph.size()), visited(graph.size()), res(graph.size()) {
            int sz = graph.size();
            for (int i = 0; i < sz; i++) {
                for (const int& nhbr: graph[i]) {
                    rev_graph[nhbr].push_back(i);
                }
            }
            // cout << "Reverse Graph ready\n";
            std::fill(visited.begin(), visited.end(), false);
            int start = graph[0].size() ? 0 : 1;
            for (int i = start; i < sz; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    travel(i);
                }
            }
            // cout << "DFS1 done \n";
            std::fill(res.begin(), res.end(), -1);
            while (!st.empty()) {
                int curr = st.top();
                st.pop();
                if (res[curr] != -1) {
                    continue;
                }
                queue<int> q;
                q.push(curr);
                res[curr] = comp;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (const int& nhbr: rev_graph[node]) {
                        if (res[nhbr] == -1) {
                            q.push(nhbr);
                            res[nhbr] = comp;
                        }
                    }

                }
                comp++;
            }
        }

        int get_num_comp () { return comp-1; }
        int find_comp (const int& node) { return res[node]; }
};

class TarjanSolver {
    private:
        const vector<vector<int>> graph;
        vector<int> discover;
        vector<int> low_link;
        stack<int> st;
        vector<bool> on_stack;
        vector<int> res;
        int comp = 1;
        int time = 0;

        void travel (int curr) {
            discover[curr] = low_link[curr] = ++time;
            st.push(curr);
            on_stack[curr] = true;
            for (const int& nhbr: graph[curr]) {
                if (discover[nhbr] == -1)  {
                    travel(nhbr);
                    low_link[curr] = min(low_link[curr], low_link[nhbr]);
                } else if (on_stack[nhbr]) {
                    low_link[curr] = min(low_link[curr], low_link[nhbr]);
                }
            }

            if (low_link[curr] == discover[curr]) {
                while (st.top() != curr) {
                    on_stack[st.top()] = false;
                    low_link[st.top()] = low_link[curr];
                    res[st.top()] = comp;
                    st.pop();
                }
                // for curr
                on_stack[st.top()] = false;
                low_link[st.top()] = low_link[curr];
                res[st.top()] = comp;
                st.pop();
                comp++;
            }
        }
    public:
        TarjanSolver (const vector<vector<int>>& graph) : graph(graph), discover(graph.size()), low_link(graph.size()), on_stack(graph.size()), res(graph.size()) {
            int sz = graph.size();
            std::fill(discover.begin(), discover.end(), -1);
            std::fill(on_stack.begin(), on_stack.end(), false);
            int start = graph[0].size() ? 0 : 1;
            for (int i = start; i < sz; i++) {
                if (discover[i] == -1) {
                    travel(i);
                }
            }
        }
        int get_num_comp () { return comp-1; }
        int find_comp (const int& node) { return res[node]; }
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    // KosarajuSolver scc(graph);
    TarjanSolver scc(graph);
    cout << scc.get_num_comp() << "\n";
    for (int i = 1; i <= n; i++) {
        cout << scc.find_comp(i) << ' ';
    }
    cout << "\n";
    return 0;
}