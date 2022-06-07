#include<bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        int a = n & (-n);

        if (a != n) {
            cout << a << endl;
        } else {
            int mask = 1;
            for (int i = 1; i <= 30; i++) {
                if (!(n & mask)) {
                    break;
                }

                mask = mask << 1;
            }

            cout << a + mask << endl;
        }
    }
    
    return 0;
}