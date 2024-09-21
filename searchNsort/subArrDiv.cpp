#include <bits/stdc++.h>
using namespace std;
/***
 * sum(i, j) = pref(0, j) - pref(0, i-1)
 * for LHS to be 0 mod n, RHS need to have both from same equivalence class
 */
int main () {
    int n;
    cin >> n;
    vector<int64_t> m(n);
    int64_t pref = 0ll;
    m[pref] = 1;
    int64_t res = 0ll;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        pref += a;
        
        m[(pref%n + n)%n]++; // storing count of all pref%n
    }

    for (int64_t &prefs: m) {
        // these are counts and we cna pick 2 prefix from same equivalence class so nC2
        res += prefs * (prefs - 1) / 2;
    }
    cout << res << endl;
    return 0;
}