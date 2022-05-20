#include <bits/stdc++.h>

using namespace std;

int t, n, k, x;

int main() {

    cin >> t;

    while (t--) {
        map<int, int> m;
        cin >> n;
        cin >> k;
        while (n--) {
            cin >> x;
            m[x]++;
        }

        vector<int> v;
        for (const auto &[key, value]: m) {
            if (value >= k) {
                v.push_back(key);
            }
        }

        int ln = v.size();

        if (v.size() == 0) {
            cout << "-1" << endl;
            continue;
        }

        int l = v[0], r = v[0], resL = v[0], resR = v[0];
        for (int i = 1; i < ln; i++) {
            if (v[i] - r == 1) {
                r = v[i];
            } else {
                if (resR - resL < r - l) {
                    resL = l, resR = r;
                }

                l = r = v[i];
            }
        }

        if (resR - resL < r - l) {
            resL = l, resR = r;
        }

        if (resL == 0 & resR == 0) {
            cout << "-1" << endl;
        } else {
            cout << resL << " " << resR << endl;
        }
    }

    return 0;
}
