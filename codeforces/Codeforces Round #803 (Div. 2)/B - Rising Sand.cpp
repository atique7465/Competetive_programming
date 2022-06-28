#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll n, t, m, k, x;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> k;
        vector<ll> v;

        for (ll i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }

        if (k == 1) {
            ll res = 0;
            for (ll i = 1; i < n - 1; i += 2) {
                res++;
            }
            cout << res << endl;
        } else {
            ll res = 0;
            for (ll i = 1; i < n - 1; i++) {
                if (v[i - 1] + v[i + 1] < v[i]) {
                    res++;
                }
            }
            cout << res << endl;
        }
    }

    return 0;
}