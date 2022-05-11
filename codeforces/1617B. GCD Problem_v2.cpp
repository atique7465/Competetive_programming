/*
we know the Basic Euclidean Algorithm for GCD
01. If we subtract a smaller number from a larger (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
02. Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find remainder 0.

so, gcd(y, x) <= y - x;

Constructive solution.
When n ≡ 0 (mod 2), output (n − 3, 2, 1).
When n ≡ 1 (mod4), output (⌊n/2⌋ − 1, ⌊n/2⌋ + 1,1).
When n ≡ 3 (mod4), output (⌊n/2⌋ − 2, ⌊n/2⌋ + 2,1).
 */

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, n;


int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        if (n % 2 == 0) {
            cout << n - 3 << " " << 2 << " " << 1 << endl;
        } else {
            if ((n / 2) % 2 == 0) {
                cout << (n / 2) + 1 << " " << (n / 2) - 1 << " " << 1 << endl;
            }else{
                cout << (n / 2) + 2 << " " << (n / 2) - 2 << " " << 1 << endl;
            }
        }
    }

    return 0;
}
