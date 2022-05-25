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

    queue<pair<ll, ll>> bfs;
    bfs.push(make_pair(val, 0));

    while (!bfs.empty()) {
        pair<ll, ll> root = bfs.front();

        if (root.first >= lim) {
            return root.second;
        }

        string str = to_string(root.first);
        ll ln = str.size();
        for (ll i = 0; i < ln; i++) {
            ll d = str[i] - '0';
            if (d > 1) {
                if (dp.find(root.first * d) == dp.end()) {
                    bfs.push(make_pair(root.first * d, root.second + 1));
                    dp[root.first * d] = 1;
                }
            }
        }

        bfs.pop();
    }

    return INF;
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

