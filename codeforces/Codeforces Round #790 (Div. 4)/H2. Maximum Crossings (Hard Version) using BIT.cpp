#include<bits/stdc++.h>

#define ll long long int
using namespace std;

struct FenwickTreeOneBasedIndexing {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTreeOneBasedIndexing(ll n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    ll sum(ll idx) {
        ll ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    void add(ll idx, ll delta) {
        if (idx <= 0) return;
        for (; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int main() {
    ll t, n, x;
    cin >> t;

    while (t--) {
        cin >> n;

        FenwickTreeOneBasedIndexing F(n);

        ll res = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            x = n + 1 - x;
            res += F.sum(x);
            F.add(x, 1);
        }

        cout << res << endl;
    }

    return 0;
}

