#include <bits/stdc++.h>
using namespace std;
const vector<vector<int>> dirs = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
}; 
void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    visited[i][j] = true;
    for (auto& it: dirs) {
        int x = i + it[0];
        int y = j + it[1];
        if (x >= n || x < 0 || y < 0 || y >= m || visited[x][y] || grid[x][y] != '.') {
            continue;
        }
        dfs(grid, x, y, visited);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '_'));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]=='.' && !visited[i][j]) {
                dfs(grid, i, j, visited);
                res++;
            }
        }
    }

    cout << res << endl;
    return 0;
}