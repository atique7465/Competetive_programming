#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {

    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        ll arr[n + 1];
        ll xorVal = 0L;
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            xorVal = arr[i] ^ xorVal;
        }

        if (xorVal == 0L) {
            cout << "YES" << endl;
        } else {
            ll sum = 0L;
            ll cnt = 0L;
            ll i = 1;
            while (i <= n) {
                sum ^= arr[i];
                if (sum == xorVal) {
                    sum = 0L;
                    cnt++;
                }
                i++;
            }

            if (sum == 0L and cnt > 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
