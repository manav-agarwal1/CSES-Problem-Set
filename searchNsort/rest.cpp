#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> ar;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ar.push_back({a, 1});
        ar.push_back({b, -1});
    }
    sort(ar.begin(), ar.end());
    int res = 0, temp = 0;
    for (const pair<int, int> &it: ar) {
        temp += it.second;
        res = max(res, temp);
    }
    cout << res << endl;
    return 0;
}