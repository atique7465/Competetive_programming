#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, n, m;
string str;

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        cin >> m;

        vector<string> v;

        for (ll i = 0; i < n; i++) {
            cin >> str;
            v.push_back(str);
        }

        ll min = INT_MAX;
        for (ll i = 0; i < n - 1; i++) {
            for (ll j = i + 1; j < n; j++) {
                ll diff = 0;
                for (ll k = 0; k < m; k++) {
                    diff += abs(v[i][k] - v[j][k]);
                }
                if (diff < min) {
                    min = diff;
                }
            }
        }

        cout << min << endl;
    }

    return 0;
}
