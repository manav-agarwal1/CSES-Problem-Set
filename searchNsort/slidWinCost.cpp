#include <bits/stdc++.h>
using namespace std;
multiset<int> lo;
multiset<int> hi;
int64_t sLo = 0ll;
int64_t sHi = 0ll;
void ins (const int &val, const int &k) {
    int curr = *lo.rbegin();
    if (curr < val) {
        hi.insert(val);
        sHi += val;
        if ((int) hi.size() > k/2) {
            auto it = hi.begin();
            sLo += *it;
            sHi -= *it;
            lo.insert(*it);
            hi.erase(it);

        }
    }
    else {
        lo.insert(val);
        sLo += val;
        if ((int) lo.size() > (k+1)/2) {
            auto it = lo.rbegin();
            sHi += *it;
            sLo -= *it;
            hi.insert(*it);
            lo.erase(lo.find(*it)); // erase dont work with r iterators
        }
    }
}

void er(const int &val) {
    if (hi.find(val) != hi.end()) {
        hi.erase(hi.find(val));
        sHi -= val;
    }
    else {
        lo.erase(lo.find(val));
        sLo -= val;
    }
    if (lo.empty()) {
        auto it = hi.begin();
        sLo += *it;
        sHi -= *it;
        lo.insert(*it);
        hi.erase(it);
    }
}

int64_t cost (vector<int> &a, int med, int st, int end) {
    int64_t res = 0ll;
    for (int i = st; i <= end; i++) {
        res += abs(a[i]-med);
    }
    return res;
}
inline int med(const int &k) {
    if (k%2 == 0) 
        return 0;
    return *lo.rbegin();
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &it: a) {
        cin >> it;
    }
    lo.insert(a[0]); //last elem always median as defined
    sLo += a[0];
    for (int i = 1; i < k; i++) {
        ins (a[i], k);
    }
    cout << sHi - sLo + med(k) << ' ';
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
        cout << sHi - sLo + med(k);
        if (i!=n-1) {
            cout << ' ';
        }
    }
    cout << endl;
    return 0;
}