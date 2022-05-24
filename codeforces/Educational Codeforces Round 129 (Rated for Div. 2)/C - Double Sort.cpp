#include<bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    ll t, n, m, x;
    cin >> t;

    while (t--) {
        cin >> n;
        ll a[n + 1];
        ll b[n + 1];

        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (ll i = 1; i <= n; i++) {
            cin >> b[i];
        }

        ll ck = 0;
        for (ll i = 1; i < n; i++) {
            for (ll j = i + 1; j <= n; j++) {
                if ((a[i] > a[j] && b[i] < b[j]) || (a[i] < a[j] && b[i] > b[j])) {
                    ck = 1;
                    break;
                }
            }
        }

        if (ck) {
            cout << -1 << endl;
            continue;
        }

        vector<ll> v1;
        vector<ll> v2;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n - i; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    swap(b[j], b[j + 1]);
                    v1.push_back(j);
                    v2.push_back(j + 1);
                }
            }
        }

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n - i; j++) {
                if (b[j] > b[j + 1]) {
                    swap(b[j], b[j + 1]);
                    v1.push_back(j);
                    v2.push_back(j + 1);
                }
            }
        }

        ll ln = v1.size();
        cout << ln << endl;
        for (ll i = 0; i < ln; i++) {
            cout << v1[i] << " " << v2[i] << endl;
        }
    }

    return 0;
}

