#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll t, n;
string str;

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        ll h = n / 3;
        if (n - (h * 3) == 0) {
            cout << h << " " << h + 1 << " " << h - 1 << endl;
        } else if (n - (h * 3) == 2) {
            cout << h + 1 << " " << h + 2 << " " << h - 1 << endl;
        } else {
            cout << h << " " << h + 2 << " " << h - 1 << endl;
        }
    }

    return 0;
}


