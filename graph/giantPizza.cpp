#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 2 SAT
 * 2 Satisfiability
 * If we want to enforce something to be true we add (p or p) equivalent to ~p->p in graph.
 * 
 * 1) get all the strongly connected components of the graph
 * 2) check for all pi is ~pi is there in same SCC
 * 3) rev top order
 * 
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

struct Query {
	int p;
	int q;
	bool neg_p = false;
	bool neg_q = false;
};
/**
 * @brief for m topping
 * ~top1, top1, ~top2, top2, ....
 * 
 * @return int 
 */
int main() {
    int n, m;
    cin >> n >> m;
	vector<Query> query(n);
	vector<vector<int>> graph(2*m+1);
	for (int i = 0, p, q; i < n; i++) {
		char c1, c2;
		bool neg_p, neg_q;
		cin >> c1 >> p >> c2 >> q;
		neg_p = (c1 == '-');
		neg_q = (c2 == '-');
		// given p or q
		// include ~p -> q and ~q -> p
		// negate what is given to point to what is given of other
		graph[2*p - !neg_p].push_back(2*q - neg_q);
		graph[2*q - !neg_q].push_back(2*p - neg_p);
	}
	// for (int i = 1; i <= 2*m; i++) {
	// 	cout << i << "\n\t";
	// 	for (int j: graph[i]) {
	// 		cout << j << ' ';
	// 	}
	// 	cout << '\n';
	// }
	// KosarajuSolver scc(graph);
	TarjanSolver scc(graph);
	vector<vector<int>> comps(scc.get_num_comp()+1);
	vector<char> res(m+1);
	// cout << scc.get_num_comp() << "\n";
	// for (int i = 1; i <= 2*m; i++) {
	// 	cout << scc.find_comp(i) << " ";
	// }
	// cout << "\n";
	for (int i = 1; i <= m; i++) {
		if (scc.find_comp(2*i) == scc.find_comp(2*i-1)) {
			// both lie in same scc
			// because p to true will end up implying ~p is true which is not good
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		// If id[p] > id[~p] then p is true and ~p is false
		// With Tarjan < as in our implementation higher ids are visited first
		// with Kosaraju > as in our implementation lower ids are visited first
		// Implication consitency is maintained if you assign true to q in p->q
		if (scc.find_comp(2*i) < scc.find_comp(2*i-1)) {
			res[i] = '+';
		}
		else {
			res[i] = '-';
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << res[i];
	}
	cout << "\n";
	return 0;
}