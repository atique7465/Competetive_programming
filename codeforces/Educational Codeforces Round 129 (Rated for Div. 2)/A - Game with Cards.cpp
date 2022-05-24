#include<bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    ll t, n, m, x;
    cin >> t;

    while (t--) {
        ll alice = 0, bob = 0;
        cin >> n;
        while (n--) {
            cin >> x;
            if (x > alice) {
                alice = x;
            }
        }

        cin >> m;
        while (m--) {
            cin >> x;
            if (x > bob) {
                bob = x;
            }
        }

        if (alice == bob) {
            cout << "Alice" << endl << "Bob" << endl;
        } else {
            if (alice > bob) {
                cout << "Alice" << endl << "Alice" << endl;
            } else {
                cout << "Bob" << endl << "Bob" << endl;
            }
        }
    }

    return 0;
}

