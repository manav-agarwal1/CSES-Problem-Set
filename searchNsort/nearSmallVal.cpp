#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<pair<int, int>> s;
    s.push({0, 0}); // base case
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        while(!s.empty() && s.top().first>=t) {
            s.pop();
        }
        cout << s.top().second << ' ';
        s.push({t, i});
    }
    cout << endl;
}