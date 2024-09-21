#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int sz = 1<<10;
/**
 * @brief Treat every column as a 10 bit number and initialized to 0, as place tile we flip the bit, so each bit represents row of that column
 * dp[i][mask] = number of ways to fill the grid from ith column to mth column such that the ith column arrangement due to (i-1)th column is represented by mask
 * @return int 
 */
vector<vector<int>> dp(1001, vector<int>(sz, 0));

void fill_col (int& n, int col, int idx, int curr_mask, int next_mask) {
    if (idx == n) {
        ( dp[col+1][next_mask] += dp[col][curr_mask] ) %= MOD;
        return;
    }
    if (curr_mask&(1<<idx)) {
        // current pos filled from previous column
        fill_col(n, col, idx+1, curr_mask, next_mask);
    }
    else {
        // horzntal
        fill_col(n, col, idx+1, curr_mask, next_mask|(1<<idx));
        if (idx+1<n && ((curr_mask&(1<<(idx+1)))==0)) {
            // vert
            fill_col(n, col, idx+2, curr_mask, next_mask);
        }
    }

}
int main () {
    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;

    for (int col = 0; col < m; col++) {
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[col][mask] > 0) {
                fill_col(n, col, 0, mask, 0);
            }
        }
    }
    cout << dp[m][0] << endl;
    return 0;
}