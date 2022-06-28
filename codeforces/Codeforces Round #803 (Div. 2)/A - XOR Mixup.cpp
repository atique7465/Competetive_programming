#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll n, t, m, k, x;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> v;

        for (ll i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }

        for (ll i = 0; i < n; i++) {
            ll xorVal = 0;
            for (ll j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                xorVal ^= v[j];
            }
            if (v[i] == xorVal) {
                cout << v[i] << endl;
                break;
            }
        }
    }

    return 0;
}