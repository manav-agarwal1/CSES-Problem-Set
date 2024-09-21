#include <bits/stdc++.h>
using namespace std;
multiset<int> lo;
multiset<int> hi;
void ins (const int &val, const int &k) {
    int curr = *lo.rbegin();
    if (curr < val) {
        hi.insert(val);
        if ((int) hi.size() > k/2) {
            auto it = hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
    }
    else {
        lo.insert(val);
        if ((int) lo.size() > (k+1)/2) {
            auto it = lo.rbegin();
            hi.insert(*it);
            lo.erase(lo.find(*it)); // erase dont work with r iterators
        }
    }
}

void er(const int &val) {
    if (hi.find(val) != hi.end()) {
        hi.erase(hi.find(val));
    }
    else {
        lo.erase(lo.find(val));
    }
    if (lo.empty()) {
        auto it = hi.begin();
        lo.insert(*it);
        hi.erase(it);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &it: a) {
        cin >> it;
    }
    lo.insert(a[0]); //last elem always median as defined
    for (int i = 1; i < k; i++) {
        ins (a[i], k);
    }
    cout << *lo.rbegin() << ' ';
    for (int i = k; i < n; i++) {
        // done to handle the implementation connect with balancing and you will know
        if (k==1) {
            ins(a[i], k);
            er(a[i-k]);
        }
        else {
            er(a[i-k]);
            ins(a[i], k);
        }
        cout << *lo.rbegin() << ' ';
    }
    cout << endl;
    return 0;
}