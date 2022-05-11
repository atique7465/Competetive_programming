#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, n, q, x, v;
vector<ll> input;

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        cin >> q;

        for (ll i = 0; i < n; i++) {
            cin >> x;
            input.push_back(x);
        }

        sort(input.begin(), input.end());

        for (ll i = n - 2; i >= 0; i--) {
            input[i] = input[i] + input[i + 1];
        }

        while (q--) {
            cin >> v;

            ll pos = -1;
            ll start = 0, end = n - 1, mid;
            while (start <= end) {
                mid = (start + end) / 2;
                if (input[mid] == v) {
                    pos = mid;
                    break;
                } else if (input[mid] > v) {
                    start = mid + 1;
                    pos = mid;
                } else {
                    end = mid - 1;
                }
            }

            if (pos == -1) {
                cout << -1 << endl;
            } else {
                cout << n - pos << endl;
            }
        }
        
        input.clear();
    }

    return 0;
}
