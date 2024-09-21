#include <bits/stdc++.h>
using namespace std;
struct range {
    int l, r, idx;
    bool operator<(const range& other) const{
        // If left ends are equal, the range with larger
        // right end comes first
        if (l == other.l)
            return r > other.r;
        // Otherwise, the range with smaller left end comes
        // first
        return l < other.l;
    }
};

int main() {
    int n;
    cin >> n;
    vector<range> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> res(2, vector<int>(n, 0));
    // as move left we are going to earlier starts so only end we need to check
    for (int i = n-1, min_end = INT_MAX; i >= 0; i--) {
        if (a[i].r >= min_end) {
            res[0][a[i].idx]++;
        }
        min_end = min(min_end, a[i].r);
    }

    for (int i = 0, max_end = 0; i < n; i++) {
        if (a[i].r <= max_end) {
            res[1][a[i].idx]++;
        }
        max_end = max(max_end, a[i].r);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}