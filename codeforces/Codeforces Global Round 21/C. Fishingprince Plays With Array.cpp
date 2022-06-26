#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll n, t, m, k, x;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> m;

        vector<pair<ll, ll>> v1;
        vector<pair<ll, ll>> v2;

        ll currPos = -1;
        for (ll i = 1; i <= n; i++) {
            cin >> x;
            ll xp = x;
            while (xp % m == 0) {
                xp /= m;
            }

            ll cnt = x / xp;
            if (currPos != -1 && v1[currPos].first == xp) {
                v1[currPos].second += cnt;
            } else {
                v1.push_back(make_pair(xp, cnt));
                currPos++;
            }
        }

        cin >> k;
        currPos = -1;
        for (ll i = 1; i <= k; i++) {
            cin >> x;
            ll xp = x;
            while (xp % m == 0) {
                xp /= m;
            }

            ll cnt = x / xp;
            if (currPos != -1 && v2[currPos].first == xp) {
                v2[currPos].second += cnt;
            } else {
                v2.push_back(make_pair(xp, cnt));
                currPos++;
            }
        }

        if (v1.size() != v2.size()) {
            cout << "no" << endl;
        } else {
            ll ck = 1;
            ll ln = v1.size();
            for (ll i = 0; i < ln; i++) {
                if (v1[i].first != v2[i].first || v1[i].second != v2[i].second) {
                    ck = 0;
                    break;
                }
            }
            if (ck) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}