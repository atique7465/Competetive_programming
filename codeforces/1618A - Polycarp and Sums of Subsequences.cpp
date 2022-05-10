#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, x;

int main() {

    cin >> t;

    while (t--) {
        vector<ll> v;
        for (ll i = 1; i <= 7; i++) {
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        cout << v[0] << " " << v[1] << " " << v[v.size() - 1] - v[0] - v[1] << endl;

    }

    return 0;
}
