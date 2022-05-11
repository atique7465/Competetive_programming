#include bitsstdc++.h

#define ll long long int
using namespace std;

ll t, n, x;

int main() {

    cin  t;

    while (t--) {
        cin  n;
        vectorll v;
        for (ll i = 0; i  n; i++) {
            cin  x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        ll res = 0;
        for (ll i = 1; i  n; i++) {
            res += v[i] - v[0];
        }

        cout  res  endl;
    }

    return 0;
}
