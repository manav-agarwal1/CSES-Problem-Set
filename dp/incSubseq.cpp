#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (s.find(x) == s.end()) {
            auto it = s.upper_bound(x);
            if (it != s.end()) {
                s.erase(it);
            }
            s.insert(x);
        }
    }

    cout << s.size() << "\n";
    return 0;
}