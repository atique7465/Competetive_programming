#include<bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, n, i, j, x;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        set<ll> st;
        map<ll, ll> mp;
        for (i = 0; i < n; i++) {
            cin >> x;
            st.insert(x);
            mp[x]++;
        }

        ll unique = st.size();

        for (auto e: st) {
            if (mp[e] > 1) {
                unique++;
            }
        }

        if (unique % 2 == 0) {
            cout << unique / 2 << endl;
        } else {
            cout << (unique / 2) + 1 << endl;
        }
    }

    return 0;
}

