#include <bits/stdc++.h>
using namespace std;
// bool place(vector<vector<int>>& graph, vector<int>& res, int curr, int team) {  
//     if (res[curr] == -1) {
//         res[curr] = team;
//     }  
//     for (int& nhbr: graph[curr]) {
//         if (res[nhbr] != -1) {
//             if (res[nhbr] != res[curr]) {
//                 continue;
//             }
//             return false;
//         }
//         bool sig = place(graph, res, nhbr, (res[curr]+1)%2);
//         if (!sig) {
//             return false;
//         };
//     }
//     return true;
// }
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> res(n+1, -1);
    queue<int> q;
    for (int i = 1, col; i <= n; i++) {
        // graph can have disconnected components
        if (res[i]==-1) {
            q.push(i);
            res[i] = col = 0;
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            col = res[curr];
            (col += 1) %= 2;
            for (int& nhbr: graph[curr]) {
                if (res[nhbr] != -1) {
                    if (res[nhbr] != col) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                    continue;
                }    
                res[nhbr] = col;
                q.push(nhbr);
                
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     if (res[i] == -1) {
    //         // cout << i << "->\n";
    //         bool sig = place(graph, res, i, 0);
    //         if (!sig) {
    //             cout << "IMPOSSIBLE\n";
    //             return 0;
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++) {
        cout << res[i]+1 << ' ';
    }
    cout << "\n";
    return 0;
}