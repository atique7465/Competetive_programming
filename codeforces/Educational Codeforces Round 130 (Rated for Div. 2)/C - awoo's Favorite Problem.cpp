#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll n, q, val, x, y;
string s, t;

int main() {
    cin >> q;

    while (q--) {
        cin >> n;
        cin >> s;
        cin >> t;

        ll i = 0, j = 0, bLast = -1, cLast = -1;

        ll ck = 1;
        while (i < n && j < n) {
            if (s[i] == t[j]) {
                j++;
                i++;
                while (s[i] == 1) {
                    i++;
                }
                if (cLast < i) {
                    cLast = i - 1;
                }
                if (bLast < i) {
                    bLast = i - 1;
                }
            } else if (t[j] == 'c') {
                while (cLast + 1 < n && s[cLast + 1] == 'b') {
                    cLast++;
                }
                if (cLast + 1 < n && s[cLast + 1] == 'c') {
                    s[cLast + 1] = 1;
                    cLast++;
                    j++;
                } else {
                    ck = 0;
                    break;
                }
            } else if (t[j] == 'b') {
                while (bLast + 1 < n && s[bLast + 1] == 'a') {
                    bLast++;
                }
                if (bLast + 1 < n && s[bLast + 1] == 'b') {
                    s[bLast + 1] = 1;
                    bLast++;
                    j++;
                } else {
                    ck = 0;
                    break;
                }
            } else {
                ck = 0;
                break;
            }
        }

        if (ck) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}


