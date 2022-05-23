#include<bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, n, x;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        ll res = -1;

        for (ll i = 0; i < n; i++) {
            cin >> x;
            if (x != i) {
                if (res == -1) {
                    res = x;
                } else {
                    res &= x;
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}

