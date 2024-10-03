#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int N = 2e5+1;
int graph[N];
bool visited[N];
int res[N];
queue<int> path;
/**
 * @brief 
 * Case 1: a->b->c->d->....som node|
 *                   ^             |
 *                   |_____________|
 * We can either be at the tail or in the cycle
 * @param node 
 * @param steps 
 */
void jump (int node, int& steps) {
    path.push(node);
    if (visited[node]) {
        steps += (res[node]==inf ? 0 : res[node]);
        return;
    }
    visited[node] = true;
    steps++;
    jump(graph[node], steps);
}
int main() {   
    // Set
    fill(res, res + N, inf);
    fill(visited, visited + N, false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> graph[i];
    }

    for (int node = 1, steps = 0, dec = 1; node <= n; node++) {
        if (!visited[node]) {
            steps = 0;
            jump(node, steps);
            dec = 1; // in case the node is on the tail in which case repeat node is only visited once
            while (!path.empty()) {
                if (path.front() == path.back()) {
                    dec = 0;
                }
                res[path.front()] = steps;
                steps -= dec;
                path.pop();
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << "\n";
    return 0;
}