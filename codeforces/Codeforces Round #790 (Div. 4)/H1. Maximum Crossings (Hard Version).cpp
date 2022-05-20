#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll t, n, i, j, x;

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> v;
        for (i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }

        ll res = 0, curr = 0;
        for (i = n - 1; i >= 0; i--) {
            for (j = i - 1; j >= 0; j--) {
                if (v[j] >= v[i]) {
                    curr++;
                }
            }
            res += curr;
            curr = 0;
        }

        cout << res << endl;
    }

    return 0;
}

