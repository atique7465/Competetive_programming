#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll t;
string str;

int main() {

    cin >> t;

    while (t--) {
        cin >> str;
        int l = 0, r = 0;
        for (int i = 0; i < 3; i++) {
            l += str[i] - '0';
        }

        for (int i = 3; i < 6; i++) {
            r += str[i] - '0';
        }

        if (l == r) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
