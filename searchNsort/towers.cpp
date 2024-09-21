#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> s;
    int res = 0;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        auto it = s.upper_bound(temp);
        if (it==s.end()) {
            res++;
        }
        else {
            s.erase(it);
        }
        s.insert(temp);
    }
    cout << res << endl;
    return 0;
}