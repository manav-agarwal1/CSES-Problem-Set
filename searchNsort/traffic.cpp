#include <bits/stdc++.h>
using namespace std;

int main() {
    // this wont pass without this
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    set<int> s1{0, n};
    multiset<int> s{n};
    for (int i = 0, temp; i < m; i++) {
        cin >> temp;
        auto it = s1.upper_bound(temp);
        auto it2 = it;
        (--it2);
        s.erase(s.find(*it - *it2)); // find only erase one instance
        s.insert(temp - *it2);
        s.insert(*it - temp);
        s1.insert(temp);
        cout << *(--s.end()) << ' ';
    }
    cout << endl;
    return 0;
}