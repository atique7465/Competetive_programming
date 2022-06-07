#include<bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    ll t, n, x;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> v;
        ll odd = 0, even = 0, evenCanBeOdd = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            if (x % 2 == 0) {
                v.push_back(x);
                even++;
                if ((x / 2) % 2 != 0) {
                    evenCanBeOdd++;
                }
            } else {
                odd++;
            }
        }

        if (odd > 0 || evenCanBeOdd > 0) {
            cout << even << endl;
        } else {
            ll cntMn = INT_MAX;
            for (ll i = 0; i < n; i++) {
                ll cnt = 0;
                ll curr = v[i];
                while (curr % 2 == 0) {
                    curr /= 2;
                    cnt++;
                }
                if (cnt < cntMn) {
                    cntMn = cnt;
                }
            }
            cout << cntMn + (even - 1) << endl;
        }
    }

    return 0;
}