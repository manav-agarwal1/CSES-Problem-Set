#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
/**
 * @brief 
 * If both a, b are in 2 differen disconnected component then we cant reach
 * If a, b both are part of same subtree then we can only reach them if distance of a from subcycle is larger than distance of b to sybcycle
 * 
 * If a and b both in subcycle then we can always reach
 * If a is in subcycle and b is in a substree then we can never reach b
 * If b is in a subcycle and a is in a subtree we can always reach b
 * 
 * 
 * 1) Find which nodes are part of which cycle
 * 
 * 2) Distance of each node to all the subcyle and check whether a and b are in same component
 */
const int MAX = 2e+5;
const int MAX_D = 20; // larger than log2(MAX)
vector<vector<int>> binLiftTable(MAX_D, vector<int>(MAX, -1));
inline int jump (int node, int num) {
    for (int i = MAX_D-1; i >= 0; i--) {
        if (num&(1<<i)) {
            node = binLiftTable[i][node];
        }
    }
    return node;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<int> next(n+1);
    vector<vector<int>> before(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> next[i];
        before[next[i]].push_back(i);
        binLiftTable[0][i] = next[i];
    }
    // Binary Lift Table
    for (int k = 1; k < MAX_D; k++) {
        for (int node = 1, mid; node <= n; node++) {
            mid = binLiftTable[k-1][node];
            binLiftTable[k][node] = binLiftTable[k-1][mid];
        }
    }
#if 0
    cout << "Binary lifting table \n";
    for (int k = 0; k < MAX_D; k++) {
        cout << k << ": ";
        for (int node = 1; node <= n; node++) {
            cout << "\t" << binLiftTable[k][node] << ' ';
        }
        cout << "\n";
    }
#endif

    // Find which nodes are part of which cycle
    vector<int> cycle_id(n+1, -2); // -2 = not processed
    vector<map<int, int>> cycles; // for each cycle we store the order of element in this map as that will help us in the case when both a and b are in the cycle
    for (int node = 1, curr; node <= n; node++) {
        if (cycle_id[node] != -2) {
            continue;
        }
        vector<int> path{node};
        curr = node;
        while (cycle_id[next[curr]] == -2) {
            curr = next[curr];
            cycle_id[curr] = -3; // in current path
            path.push_back(curr);
        }
        map<int, int> cycle;
        bool in_cycle = false;
        for (int i : path) {
            // this is only set once at the start of cycle
            in_cycle = in_cycle || (i==next[curr]); // curr is at the node now if this is a cycle, or at some other node which is just before some other cycle or tree node, it can also be in a cycle if node had send in a cycle
            cycle_id[i] = -1;
            if (in_cycle) {
                cycle[i] = cycle.size();
                cycle_id[i] = cycles.size();
            }
        }
        if (cycle.size()) {
            // Dont push empty cycles
            cycles.push_back(cycle);
        }
    }
#if 0
    cout << "Cycles \n";
    for (int i = 1; i <= n; i++) {
        cout << i << " => " << cycle_id[i] << endl;
    }
    for (auto& it: cycles) {
        cout << "Cycle =>\n";
        for (auto& pi: it) {
            cout << "\t" << pi.first << ' ' << pi.second << "\n";
        }
    }
#endif
    // Precalculating distance of all the nodes from cycle
    vector<int> cycle_dist(n+1, inf);
    for (int node = 1, curr; node <= n; node++) {
        if (cycle_id[next[node]] == -1) {
            // if current node is like a->b->c ..->cycle so for a and b I dont want to run
            // or current node is a cycle
            continue;
        }
        if (cycle_id[node] >= 0) {
            cycle_dist[node] = 0;
        }
        else {
            cycle_dist[node] = 1;
            // queue will also work
            vector<int> stack(before[node]);
            while (!stack.empty()) {
                curr = stack.back();
                stack.pop_back();
                cycle_dist[curr] = cycle_dist[next[curr]] + 1;
                stack.insert(stack.end(), before[curr].begin(), before[curr].end());
            }
        }
    }
#if 0
    cout << "Printing Cycle Distances \n";
    for (int i = 1; i <= n; i++) {
        cout << "\t" << cycle_dist[i] << " ";
    }
    cout << "\n";
#endif

    // Processing queries
    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        // cout << cycle_id[binLiftTable[MAX_D-1][a]] << ' ' << cycle_id[binLiftTable[MAX_D-1][b]] << endl;
        if (cycle_id[binLiftTable[MAX_D-1][a]] != cycle_id[binLiftTable[MAX_D-1][b]]) {
            // both are not in same cycle
            // cout << "A ";
            cout << "-1\n";
            continue;
        } 
        if (cycle_id[a] != -1 || cycle_id[b] != -1) {
            if (cycle_id[b] == -1 && cycle_id[a] >= 0) {
                // dst in tree but source in cycle so since we cant escape cycle
                // cout << "B ";
                cout << "-1\n";
                continue;
            }
            // dst in cycle and source is in tree
            // jmp a to cycle
            // cout << "C ";
            int temp = cycle_dist[a];
            // cout <<  temp << ' ';
            a = jump(a, temp);
            // cout << a << ' ';
            int idx = cycle_id[a];
            int pos1 = cycles[idx][a];
            int pos2 = cycles[idx][b];
            // cout << a << ' ' << b << ' ' << pos1 << ' ' << pos2 << "\n";
            if (pos2 >= pos1) {
                cout << temp + pos2 - pos1 << "\n";
            }
            else {
                cout << temp + ((int)cycles[idx].size() - (pos1 - pos2)) << "\n";
            }
        }
        else {
            // both lie in a tree
            // cout << "D ";
            if (cycle_dist[b] > cycle_dist[a]) {
                cout << "-1\n";
                continue;
            }
            // it is possible we are 2 different components
            // So
            int temp = cycle_dist[a] - cycle_dist[b];
            cout << ((jump(a, temp) == b) ? temp : -1) << "\n";
        }
    }
    return 0;
}