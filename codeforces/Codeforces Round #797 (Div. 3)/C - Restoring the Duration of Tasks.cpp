#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll t, n, x, i;

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> s;
        vector<ll> f;
        for (i = 0; i < n; i++) {
            cin >> x;
            s.push_back(x);
        }

        for (i = 0; i < n; i++) {
            cin >> x;
            f.push_back(x);
        }

        for (i = 0; i < n; i++) {
            if (i == 0) {
                cout << f[i] - s[i];
            } else {
                cout << f[i] - max(f[i - 1], s[i]);
            }
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


