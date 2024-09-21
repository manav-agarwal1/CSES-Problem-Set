#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &it: a) {
        cin >> it;
    }
    multiset<int> s(a.begin(), a.end());
    for (int i = 0, t; i < m; ++i) {
		cin >> t;
		auto it = s.upper_bound(t);
		if (it == s.begin()) {
			cout << -1 << "\n";
		} else {
			cout << *(--it) << "\n";
			s.erase(it);
		}
	}
    return 0;
}