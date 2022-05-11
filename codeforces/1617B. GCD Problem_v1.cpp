/*
 * Brute force from a=2,3,4,… and calculate the value of b (b=n−a−1), then check whether gcd(a,b)=1.
 * It works, because you will find a prime number p≤29 such that n−1 does not divide p.
 */

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, n;


int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        for (ll i = 2; i <= 29; i++) {
            if (gcd(n - i - 1, i) == 1) {
                cout << i << " " << n - i - 1 << " " << 1 << endl;
                break;
            }
        }
    }

    return 0;
}
