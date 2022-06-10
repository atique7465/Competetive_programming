#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll t, n;
string str;

int main() {

    cin >> t;

    while (t--) {
        char ch = 0;
        cin >> n;
        n = (2 * n) + 1;
        while (n--) {
            cin >> str;
            for (auto c: str) {
                ch ^= c;
            }
        }

        cout << ch << endl;
    }

    return 0;
}


