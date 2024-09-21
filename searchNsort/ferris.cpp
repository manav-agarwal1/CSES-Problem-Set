#include <bits/stdc++.h>
using namespace std;

// 2 constraints
// weight limit + number limit
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &it: a) {
        cin >> it;
    }
    sort(a.begin(), a.end());
    // for (auto &it: a) {
    //     cout << it << ' ';
    // }
    // cout << endl;
    int res = 0;
    for (int i = 0, j = n-1; i <= j; res++) {
        if (a[i]+a[j] <= x) {
            i++;
            j--;
        }
        else {
            j--;
        }
    }
    cout << res << endl;
    return 0;
}