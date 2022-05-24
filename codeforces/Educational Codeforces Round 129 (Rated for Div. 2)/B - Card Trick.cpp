#include<bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    ll t, n, m, x;
    cin >> t;

    while (t--) {
        cin >> n;
        ll arr[n + 1];
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        ll tot = 0;
        cin >> m;
        while (m--) {
            cin >> x;
            tot = (tot + (x % n)) % n;
        }

        tot = tot % n;

        cout << arr[1 + tot] << endl;
    }

    return 0;
}

