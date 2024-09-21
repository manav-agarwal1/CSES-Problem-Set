#include <bits/stdc++.h>
using namespace std;
const vector<vector<int>> dirs = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
}; 
const string dirMap = "RDLU";
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '_'));
    vector<vector<char>> parent(n, vector<char>(m, '?'));
    vector<vector<int>> path(n, vector<int>(m, -1));
    queue<pair<pair<int, int>, char>> q;
    pair<int, int> curr, a_pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                q.push({{i, j}, 'M'});
                parent[i][j] = 'G';
            }
            else if (grid[i][j] == 'A') {
                curr = {i, j};
            }
        }
    }
    q.push({curr, 'A'}); // we push the A pos at last so all monsters and their nhbrs are processed first
    parent[curr.first][curr.second] = 'G';
    // Kind of giving A ability to look forward in time
    a_pos = curr;
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        curr = it.first;
        // cout << curr.first << ' ' << curr.second << endl;
        // reach boundary
        if ((parent[curr.first][curr.second] == 'A') && (curr.first == 0 || curr.first == n-1 || curr.second == 0 || curr.second == m-1)) {
            // boundary reached start path construction
            a_pos = curr;
            break;
        }

        // try to find boundary
        for (int i = 0, x, y; i < 4; i++) {
            x = curr.first + dirs[i][0]; 
            y = curr.second + dirs[i][1];
            if (x >= n || x < 0 || y < 0 || y >= m || parent[x][y] != '?' || grid[x][y] == '#') {
                continue;
            }
            parent[x][y] = it.second;
            path[x][y] = i;
            q.push({{x, y}, it.second});
        }
    }
    // Writing this loop out this way helps handle edge cases without too many if conditions
    // cout << a_pos.first << ' ' << a_pos.second << endl;
    if (a_pos.first == 0 || a_pos.first == n-1 || a_pos.second == 0 || a_pos.second == m-1) {
        string res = "";
        while (parent[a_pos.first][a_pos.second] != 'G') {
            int idx = path[a_pos.first][a_pos.second];
            res += dirMap[idx];
            a_pos.first -= dirs[idx][0];
            a_pos.second -= dirs[idx][1];
        }
        reverse(res.begin(), res.end());
        cout << "YES\n" << res.size() << "\n";
        if (res.size()) {
            cout << res << "\n";
        }
    }
    else {
        cout << "NO\n";
    }
    return 0;
}