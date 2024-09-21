#include <bits/stdc++.h>
using namespace std;
const vector<vector<int>> dirs = {
    {0, 1}, // R
    {1, 0}, // D
    {0, -1}, // L
    {-1, 0}, // U
}; 
const string dirMap = "RDLU";

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    vector<vector<int>> path(n, vector<int>(m, -1));
    pair<int, int> start = {-1, -1};
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j]=='A') {
                start = {i, j};
                q.push(start);
                visited[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        if (grid[it.first][it.second] == 'B') {
            cout << "YES\n";
            string res = "";
            while (it != start) {
                int idx = path[it.first][it.second];
                res += dirMap[idx];
                it.first -= dirs[idx][0];
                it.second -= dirs[idx][1];
            }
            reverse(res.begin(), res.end());
            cout << res.size() << "\n" << res << "\n";
            return 0;
        }
        for (int i = 0, x, y; i < 4; i++) {
            x = it.first + dirs[i][0]; 
            y = it.second + dirs[i][1]; 
            if (x >= n || x < 0 || y < 0 || y >= m || visited[x][y] || grid[x][y] == '#') {
                continue;
            }
            visited[x][y] = true;
            path[x][y] = i;
            q.push({x, y});
        }
    }
    cout << "NO\n";
    return 0;
}