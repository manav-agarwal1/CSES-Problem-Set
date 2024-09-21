#include <bits/stdc++.h>
using namespace std;
const int PATH_LEN = 48;
int PATH[PATH_LEN];
const int DIR_LEN = 4;
const int DIR[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //
const int N = 9; // add padding from all side
bool GRID[N][N];
int traverse(int start, int r, int c) {
    // Pruning
    if (GRID[r][c-1] && GRID[r][c+1] && !GRID[r-1][c] && !GRID[r+1][c]) {
        return 0;
    }
    if (GRID[r-1][c] && GRID[r+1][c] && !GRID[r][c-1] && !GRID[r][c+1]) {
        return 0;
    }
    // Just below gives TLE 
    if (r==7 && c==1) {
        return start==PATH_LEN;
    }
    if (start==PATH_LEN) {
        return 0;
    }
    int res = 0;
    GRID[r][c] = true;
    
    if (PATH[start] < 4) {
        int x = r + DIR[PATH[start]][0];
        int y = c + DIR[PATH[start]][1];
        if (!GRID[x][y]) {
            res += traverse(start+1, x, y);
        }
    }
    // these special cases are not needed at all for C++, though done for learning
    else if ((c>2) && (GRID[r][c-2] && (GRID[r-1][c-1] || GRID[r+1][c-1]) && !GRID[r][c-1])) {
        res += traverse(start+1, r, c-1);
    } 
    else if ((c<6) && (GRID[r][c+2] && (GRID[r-1][c+1] || GRID[r+1][c+1]) && !GRID[r][c+1])) {
        res += traverse(start+1, r, c+1);
    }
    else if ((r>2) && (GRID[r-2][c] && (GRID[r-1][c-1] || GRID[r-1][c+1]) && !GRID[r-1][c])) {
        res += traverse(start+1, r-1, c);
    }
    else if ((r<6) && (GRID[r+2][c] && (GRID[r+1][c-1] || GRID[r+1][c+1]) && !GRID[r+1][c])) {
        res += traverse(start+1, r+1, c);
    }
    else {
        for (int i = 0; i < DIR_LEN; i++) {
            int x = r + DIR[i][0];
            int y = c + DIR[i][1];
            if (!GRID[x][y]) {
                res += traverse(start+1, x, y);
            }
        }
    }
    GRID[r][c] = false; // so other paths can use this cell
    return res;
}
int main() {
    string s;
    int res = 0;
    cin >> s;

    for (int i = 0; i < 48; i++) {
        if (s[i]=='U') PATH[i] = 0;
        else if (s[i]=='R') PATH[i] = 1;
        else if (s[i]=='D') PATH[i] = 2;
        else if (s[i]=='L') PATH[i] = 3;
        else PATH[i] = 4;
    }
    
    for (int i = 0; i < N; i++) {
        GRID[i][0] = true;
        GRID[0][i] = true;
        GRID[N-1][i] = true;
        GRID[i][N-1] = true;
    }
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= N-2; j++) {
            GRID[i][j] = false;
        }
    }
    res = traverse(0, 1, 1);
    cout << res << endl;
    return 0;
}