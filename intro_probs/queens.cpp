#include <bits/stdc++.h>
using namespace std;
void helper(int q, vector<string>& b, vector<bool>& c, vector<bool>& d1, vector<bool>& d2, int& res) {
    if(q==8) {
        res++;
        return;
    }
    for (int j = 0; j < 8; j++) {
        if (b[q][j]=='*' || c[j] || d1[q+j] || d2[q-j+8]) {
            continue;
        }
        c[j] = d1[q+j] = d2[q-j+8] = true;
        helper(q+1, b, c, d1, d2, res);
        c[j] = d1[q+j] = d2[q-j+8] = false;
    }
}
int main() {
    vector<string> b(8);
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        // cout << s.size() << endl;
        b[i] = s;
    }
    int res = 0;
    vector<bool> c(8), d1(14), d2(14);
    helper(0, b, c, d1, d2, res);
    cout << res << endl;
    return 0;
}