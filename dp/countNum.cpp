#include <bits/stdc++.h>
using namespace std;
/**
 * @brief https://www.youtube.com/watch?v=lD_irvBkeOk
 * Standard digit dp
 * 
 * @return int 
 */

int64_t dp[20][10][2][2];
int64_t helper(string& N, int d, int x, bool lead_zero, bool tight) {
    if (d==0) {
        return 1ll;
    }
    if (x!=-1 && dp[d][x][lead_zero][tight]!=-1) {
        return dp[d][x][lead_zero][tight];
    }
    int minn = 0;
    int maxx = tight ? (N[N.size()-d]-'0'): 9;
    int64_t res = 0ll;

    for (int dig = minn; dig <= maxx; dig++) {
        if (dig == x && lead_zero == 0) {
            continue;
        }
        res += helper(N, d-1, dig, lead_zero && (dig==0), tight && (dig==maxx));
    }

    return dp[d][x][lead_zero][tight]=res;
}

int main() {
    int64_t a, b;
    cin >> a >> b;
    
    string A = to_string(a-1);
    string B = to_string(b);
    memset(dp, -1, sizeof(dp));
    int64_t res1 = helper(B, B.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    cout << res1-helper(A, A.size(), -1, 1, 1) << endl;
}