#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void helper(int src, int aux, int dst, int n) {
    if (n==1) {
        cout << src << ' ' << dst << endl;
        return;
    }

    helper(src, dst, aux, n-1); // move n-1 src to aux
    cout << src << ' ' << dst << endl; // move nth from src to dst
    helper(aux, src, dst, n-1); // move from aux to dst
}
int main() {
    int n;
    cin >> n;
    
    cout << (1<<n)-1 << endl;
    helper(1, 2, 3, n);
    return 0;
}