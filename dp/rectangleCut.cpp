#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Approach1: cut smaller side from larger side and proceed till both are equal, seems this is not the most optimal strategy.
 * Say the dimensions are very close to each other but in general are large then after the first move we will be in a very bad state, so dp it is
 * 
 * @return int 
 */
int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i==j) {
                dp[i][j] = 0;
            }
            else {
                // vertical and horizontal cuts
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                }
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}