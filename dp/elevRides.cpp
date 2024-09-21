#include <bits/stdc++.h>
using namespace std;
// Greedy wont work, 3,3,2,2,2 -> greedy(3) but answer is 2
int main () {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &it: a) {
        cin >> it;
    }
    vector<pair<int, int>> dp(1<<n); // #ride, last
    dp[0] = {1, 0}; // empty ride
    for (int i = 1; i < (1<<n); i++) {
        dp[i] = {n+1, 0};
        for (int j = 0; j < n; j++) {
            pair<int, int> option = {n+1, 0};
            if (i&(1<<j)) {
                option = dp[i^(1<<j)];
                if (option.second + a[j] <= x) {
                    option.second += a[j];
                }
                else {
                    option.first++;
                    option.second = a[j];
                }
            }
            dp[i] = min(dp[i], option);
        }
    }
    cout << dp.back().first << "\n";
    return 0;
}