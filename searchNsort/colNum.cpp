#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> idx(n+1);
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        idx[temp] = i;
    }

    int res = 1;
    for (int i = 1; i < n; i++) {
        res += (idx[i+1] < idx[i]);
    }
    cout << res << "\n";
    return 0;
}