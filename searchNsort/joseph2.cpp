#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(1);
    int root = sqrt(n);
    for (int i = 1, count = 0; i <= n; i++) {
        if (count > root) {
            grid.push_back({});
            count = 0;
        }
        grid.back().push_back(i);
        count++;
    }

    int row = 0;
    int col = 0;
    for (int i = 0; i < n; i++) {
        // after i removals elems = n-i
        int tgt = k % (n-i);
        while (tgt!=0) {
            if (col+tgt < (int)grid[row].size()) {
                col += tgt;
                tgt = 0;
            }
            else {
                tgt -= ((int)grid[row].size() - col);
                col = 0;
                row++;
            }
            if(row >= (int)grid.size()) {
                row = 0;
            }
        }
        // we will move to next row if col is greater than what we have
        // if I leave the previous else condition in else block then i could end up in an empty row after some iterations to skip that we can use this
        while ((int)grid[row].size() == 0) {
            col = 0;
            row++;
            if (row >= (int)grid.size()) {
                row = 0;
            }
        }
        cout << grid[row][col] << ' ';
        if (i != n-1) {
            grid[row].erase(grid[row].begin() + col);
            // if we need to wrap to next row
            while ((int)grid[row].size() == col) {
                col = 0;
                row++;
                if (row >= (int)grid.size()) {
                    row = 0;
                }
            }
        }
    } 
    cout << endl;
    return 0;
}