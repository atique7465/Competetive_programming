#include<bits/stdc++.h>

using namespace std;

#define ll long long int
ll n, t, x;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> v;
        map<ll, ll> mp;
        ll posCnt = 0;
        ll negCnt = 0;
        ll zeroCnt = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            if (x > 0) {
                posCnt++;
                v.push_back(x);
                mp[x] = 1;
            } else if (x < 0) {
                negCnt++;
                v.push_back(x);
                mp[x] = 1;
            } else {
                zeroCnt++;
            }
        }

        if (posCnt > 2 || negCnt > 2) {
            cout << "NO" << endl;
        } else if (posCnt == 0 && negCnt == 0) {
            cout << "YES" << endl;
        } else {
            if (zeroCnt > 0) {
                zeroCnt = zeroCnt > 2 ? 2 : zeroCnt;
                while (zeroCnt--) {
                    v.push_back(0);
                }
                mp[0] = 1;
            }

            ll ck = 0;
            for (ll i = 0; i < v.size() - 2; i++) {
                for (ll j = i + 1; j < v.size() - 1; j++) {
                    for (ll k = j + 1; k < v.size(); k++) {
                        if (mp.find(v[i] + v[j] + v[k]) == mp.end()) {
                            ck = 1;
                        }
                    }
                }
            }

            if (ck) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}