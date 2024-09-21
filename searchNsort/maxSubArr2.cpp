#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> A(n);
    vector<int64_t> pref;
    pref.push_back(0);
    for (auto &it: A) {
        cin >> it;
        pref.push_back(it + pref.back());
    }
    int64_t res = LLONG_MIN;
    multiset<int64_t> s;
    for (int i = a; i <= n; i++) {
        if (i > b) {
            s.erase(s.find(pref[i-b-1]));
        }
        s.insert(pref[i-a]);
        res = max(res, pref[i]-*s.begin());
    }
    cout << res << endl;
}