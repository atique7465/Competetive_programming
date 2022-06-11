#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll t, n, x, i;

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        vector<ll> v1;
        vector<ll> v2;
        for (i = 0; i < n; i++) {
            cin >> x;
            v1.push_back(x);
        }

        for (i = 0; i < n; i++) {
            cin >> x;
            v2.push_back(x);
        }

        ll mxDiff = 0;
        for (i = 0; i < n; i++) {
            if (v1[i] - v2[i] > mxDiff) {
                mxDiff = v1[i] - v2[i];
            }
        }

        ll ck = 1;
        for (i = 0; i < n; i++) {
            ll currDiff = v1[i] - v2[i];
            if ((currDiff < 0) || (currDiff < mxDiff && v2[i] != 0)) {
                ck = 0;
                break;
            }
        }

        if (ck) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}


