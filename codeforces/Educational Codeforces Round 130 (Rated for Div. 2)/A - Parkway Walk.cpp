#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll t, n, k, m, x;

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        cin >> m;

        ll sum = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            sum += x;
        }

        if (m >= sum) {
            cout << 0 << endl;
        } else {
            cout << sum - m << endl;
        }
    }

    return 0;
}


