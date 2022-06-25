#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll n, t, z, x;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> z;

        ll mx = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            mx = max(mx, z | x);
        }

        cout << mx << endl;

    }

    return 0;
}