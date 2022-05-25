#include<bits/stdc++.h>

#define ll unsigned long long int
using namespace std;
const ll INF = 1e12;

ll n, x, lim = 1;
map<ll, ll> dp;

void findLim() {
    for (ll i = 1; i < n; i++) {
        lim *= 10;
    }
}

ll solve(ll val) {

    if (val >= lim) {
        return 0;
    }

    if (dp.find(val) != dp.end()) {
        return dp[val];
    }

    string dg = to_string(val);
    ll ans = INF;
    for (auto c: dg) {
        ll d = c - '0';
        if (d > 1) {
            ans = min(ans, 1 + solve(val * d));
        }
    }

    return dp[val] = ans;
}

int main() {
    cin >> n >> x;

    findLim();
    ll res = solve(x);

    if (res == INF) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}

