#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << ((a + b) % 3 == 0 && (min(a, b) * 2 >= max(a, b)) ? "YES" : "NO") << endl;
    }
    return 0;
}