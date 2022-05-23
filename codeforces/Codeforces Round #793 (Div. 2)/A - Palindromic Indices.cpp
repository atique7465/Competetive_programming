#include<bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, n, i, j;
string s;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> s;

        ll mid = n / 2;
        ll cnt = 0;

        i = mid;
        while (i < n) {
            if (s[i] == s[mid]) {
                cnt++;
            } else {
                break;
            }
            i++;
        }

        i = mid - 1;
        while (i >= 0) {
            if (s[i] == s[mid]) {
                cnt++;
            } else {
                break;
            }
            i--;
        }

        cout << cnt << endl;

    }

    return 0;
}

