#include <bits/stdc++.h>
using namespace std;
// solve diagonal of the max(x,y) sqaure and then calculate the value from there
int main() {
    int n;
    cin >> n;
    for (int64_t i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        if (x==y) {
            cout << x*x - (x-1ll) << endl;
        }
        else if (x>y) {
            if (x%2==1) {
                cout << (x*x-(x-1ll))-(x-y) << endl;
            }
            else {
                cout << (x*x-(x-1ll))+(x-y) << endl;
            }
        }
        else {
            if (y%2==1) {
                cout << (y*y-(y-1ll))+(y-x) << endl;
            }
            else {
                cout << (y*y-(y-1ll))-(y-x) << endl;
            }
        }
    }
    return 0;
}