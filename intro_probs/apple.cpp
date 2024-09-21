#include <bits/stdc++.h>
using namespace std;
int64_t helper(int curr, vector<int64_t>& a, int64_t s1, int64_t s2) {
    if (curr>=(int)a.size()) {
        return abs(s1-s2);

    }
    return min(helper(curr+1, a, s1+a[curr], s2), helper(curr+1, a, s1, s2+a[curr]));
}
int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& it: a) {
        cin >> it;
    }
    cout << helper(0, a, 0ll, 0ll) << endl;
    return 0;
}