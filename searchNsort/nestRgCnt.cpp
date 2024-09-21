#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

template <typename T>
using ordered_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;
    vector<range> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
    }
    sort(a.begin(), a.end());
    // for (auto& it: a) {
    //     cout << it.l << ' ' << it.r << endl;
    // }
    vector<vector<int>> res(2, vector<int>(n, 0));
    ordered_set<pair<int, int>> end_so_far;
    // as move left we are going to earlier starts so only end we need to check
    // cout << endl;
    for (int i = n-1; i >= 0; i--) {
        end_so_far.insert({a[i].r, -i});
        res[0][a[i].idx] = end_so_far.order_of_key({a[i].r, -i});
    }
    end_so_far.clear();
    for (int i = 0; i < n; i++) {
        end_so_far.insert({a[i].r, -i});
        res[1][a[i].idx] = end_so_far.size() - end_so_far.order_of_key({a[i].r, -i})-1;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}