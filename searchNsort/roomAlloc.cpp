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
    set<pair<int, int>> s; // end, room_num
    s.insert({a[0].r, 1});
    vector<int> res(n, 1);
    int n_rooms = 1;
    for (int i = 1, room; i < n; i++) {
        auto it = s.begin();
        if ((*it).first<a[i].l) {
            room = (*it).second;
            s.erase(it);
        }
        else {
            room = ++n_rooms;
        }
        s.insert({a[i].r, room});
        res[a[i].idx] = room;
    }
    cout << n_rooms << "\n";
    for (auto &it: res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}