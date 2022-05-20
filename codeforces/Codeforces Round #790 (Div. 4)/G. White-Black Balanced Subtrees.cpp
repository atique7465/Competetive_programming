#include<bits/stdc++.h>

#define ll long long int
using namespace std;
const ll MX = 4010;
vector<ll> adj[MX];
ll res = 0;
string color;
ll t, i, nodes, x;

ll DFS(ll root) {

    ll localRes = color[root - 1] == 'W' ? 1 : -1;

    ll dfsRes = 0;
    ll ln = adj[root].size();
    if (ln != 0) {
        for (ll j = 0; j < adj[root].size(); j++) {
            dfsRes += DFS(adj[root][j]);
        }
        adj[root].clear();
    }

    if (dfsRes != 0 && (dfsRes + localRes) == 0) {
        res++;
    }

    return localRes + dfsRes;
}

int main() {

    scanf("%lld", &t);

    while (t--) {
        scanf("%lld", &nodes);
        for (i = 2; i <= nodes; i++) {
            scanf("%lld", &x);
            adj[x].push_back(i);
        }

        cin >> color;

        DFS(1);
        cout << res << endl;

        res = 0;
    }

    return 0;
}

