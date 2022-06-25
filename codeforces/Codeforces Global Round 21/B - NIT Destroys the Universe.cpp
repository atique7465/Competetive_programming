#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll n, t, z, x;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        ll cnt = 0;

        ll curr = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            if (x > 0 & curr == 0) {
                cnt++;
            }
            curr = x;
        }

        ll res = 0;
        if (cnt > 0) {
            res = cnt > 1 ? 2 : 1;
        }
        cout << res << endl;
    }

    return 0;
}