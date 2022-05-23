#include<bits/stdc++.h>

#define ll long long int
using namespace std;

struct FenwickTree {
    vector<ll> bit;
    ll n;

    FenwickTree(ll n) {
        this->n = n + 1; // one based indexing
        bit.assign(n + 1, 0);
    }

//    FenwickTree(vector<ll> v) : FenwickTree(v.size()) { //less efficient [n log n]
//        for (ll i = 0; i < v.size(); i++)
//            add(i + 1, v[i]);
//    }

    FenwickTree(vector<ll> v) : FenwickTree(v.size()) { //efficient [n]
        for (ll i = 0; i < n; i++)
            bit[i + 1] = v[i];

        for (ll i = 1; i < n; i++) {
            ll idx = i + (i & -i); // get parent
            if (idx < n) {
                bit[idx] += bit[i];
            }
        }
    }

    ll sum(ll idx) {
        ll ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    ll rangeSum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        if (idx <= 0) return;
        for (; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
};

int main() {
    ll t, n, x;
    cin >> t;

    while (t--) {
        cin >> n;

        FenwickTree F(n);

        ll res = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            res += F.rangeSum(x, n);
            F.add(x, 1);
        }

        cout << res << endl;
    }

    return 0;
}

