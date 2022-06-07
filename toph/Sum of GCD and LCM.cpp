#include<bits/stdc++.h>

#define ll long long int
using namespace std;

vector<ll> prims{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
                 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
                 211, 223, 227};
ll t, glMxFact, glMaxPower;

void resolveMxPowAndFactor(ll n) {
    ll maxPowerFactor, maxPower = 0;
    for (ll i = 0; i < 30; i++) {
        ll currPower = 0;
        if (n % prims[i] == 0) {
            while (n % prims[i] == 0) {
                n /= prims[i];
                currPower++;
            }
        }
        if (currPower > maxPower) {
            maxPower = currPower;
            maxPowerFactor = prims[i];
        }
    }

    if (n > 1) {
        if (1 > maxPower) {
            maxPower = 1;
            maxPowerFactor = n;
        }
    }

    glMaxPower = maxPower;
    glMxFact = maxPowerFactor;
}

ll big_pow(ll x, ll y) {
    ll ans;
    ans = 1;
    while (y > 0) {
        if (y & 1) {
            ans = (ans * x);
        }
        x = (x * x);
        y = y >> 1;
    }
    return ans;
}


int main() {
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        if (n % 2 == 0) {
            cout << n / 2 << " " << n / 2 << endl;
        } else {

            resolveMxPowAndFactor(n);

            ll rest = n / big_pow(glMxFact, glMaxPower);
            ll a = rest * (glMaxPower == 1 ? 1 : big_pow(glMxFact, glMaxPower - (glMaxPower / 2)));

            if (a == n) {
                cout << -1 << endl;
            } else {
                cout << min(a, n - a) << " " << max(a, n - a) << endl;
            }
        }
    }

    return 0;
}


