#include <bits/stdc++.h>
using namespace std;

/**
 * @brief idea is to sort every task as per reward it gives a[right]-a[left], but if we keep task with earlier deadline very late then thats bad so we need to have a[right]-a[left]-a[right], so higher deadline task appear later
 * 
 */
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
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
        s.insert({-a[i].l, a[i].idx});
    }
    int64_t res = 0ll;
    int64_t time = 0ll;
    while (!s.empty()) {
        auto it = s.end();
        (--it);
        int idx = (*it).second;
        res += a[idx].r - a[idx].l - time;
        time += a[idx].l;
        s.erase(it);
    }
    cout << res << endl;
    return 0;
}