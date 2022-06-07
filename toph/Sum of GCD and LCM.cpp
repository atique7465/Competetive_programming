#include<bits/stdc++.h>

#define ll long long int
using namespace std;

vector<ll> primes;
ll t, primesLn;

vector<ll> getPrime() {
    bool vis[10005];
    memset(vis, false, sizeof(vis));
    ll n = 10005;
    vector<ll> pr;

    for (ll i = 2; i < n; i++) {
        if (vis[i])
            continue;
        pr.push_back(i);
        for (ll j = 2 * i; j < n; j += i)
            vis[j] = true;
    }

    return pr;
}

int main() {

    primes = getPrime();
    primesLn = primes.size();

    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        if (n % 2 == 0) {
            cout << n / 2 << " " << n / 2 << endl;
        } else {

            ll a = INT_MIN, b = INT_MAX;
            ll currN = n;
            for (ll i = 0; i < primesLn && currN > 1; i++) {
                if (currN % primes[i] == 0) {
                    ll currPower = 0;
                    ll currValue = 1;
                    while (currN % primes[i] == 0) {
                        currN /= primes[i];
                        currPower++;
                        currValue *= primes[i];
                    }

                    ll rest = n / currValue;
                    ll currA = rest * (currValue / primes[i]);

                    if (currA != n && (abs(currA - (n - currA)) < abs(a - b))) {
                        a = min(currA, n - currA), b = max(currA, n - currA);
                    }
                }
            }

            if (currN > 1) {
                ll currA = n / currN;

                if (currA != n && (abs(currA - (n - currA)) < abs(a - b))) {
                    a = min(currA, n - currA), b = max(currA, n - currA);
                }
            }

            if (a != INT_MIN) {
                cout << a << " " << b << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}


//2268945
//756315 1512630
//84230491
//269107 83961384
//1927
//47 1880