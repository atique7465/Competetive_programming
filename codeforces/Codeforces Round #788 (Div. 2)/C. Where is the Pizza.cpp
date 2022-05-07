/**
 *@author atiQue
 *@since 5/7/2022 1:27 PM
*/

/// kinda DSU

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll MOD = 1e9 + 7;
ll bIndex[100010];
ll i, n;

ll mod_pow(ll x, ll y) {
    ll ans;
    ans = 1;
    while (y > 0) {
        if (y & 1) {
            ans = (ans * x) % MOD;
        }
        x = (x * x) % MOD;
        y = y >> 1;
    }
    return ans;
}

int main() {

    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        int A[n + 1];
        int B[n + 1];
        int D[n + 1];
        for (i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> B[i];
            bIndex[B[i]] = i;
        }
        for (i = 1; i <= n; i++) {
            cin >> D[i];
            if (D[i] != 0) {
                A[i] = -1;
                B[i] = -1;
            }
        }

        ll group = 0;
        for (i = 1; i <= n; i++) {
            if (A[i] != -1 && B[i] != -1) {
                ll bCurr = B[i];
                ll bNext = A[i];
                A[i] = -1;
                B[i] = -1;
                int moreTheOne = false;
                while (bNext != bCurr) {
                    moreTheOne = true;
                    ll bNextIdx = bIndex[bNext];
                    if (B[bNextIdx] == -1) {
                        break;
                    } else {
                        bNext = A[bNextIdx];
                        A[bNextIdx] = -1;
                        B[bNextIdx] = -1;
                    }
                }

                if (moreTheOne && bNext == bCurr) {
                    group++;
                }
            }
        }

        cout << mod_pow(2, group) << endl;
    }

    return 0;
}