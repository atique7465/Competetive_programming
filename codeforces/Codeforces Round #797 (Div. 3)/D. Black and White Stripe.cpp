#include<bits/stdc++.h>

#define ll long long int
using namespace std;
ll t, n, k;
string str;

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        cin >> k;
        cin >> str;

        ll cntBlack = 0, i = 0, j = 0, minWhite = INT_MAX;
        while (j < k) {
            if (str[j] == 'B') {
                cntBlack++;
            }
            j++;
        }
        j--;

        if (k - cntBlack < minWhite) {
            minWhite = k - cntBlack;
        }

        while (j < n - 1) {
            if (str[j + 1] == 'B') {
                cntBlack++;
            }

            if (str[i] == 'B') {
                cntBlack--;
            }

            if (k - cntBlack < minWhite) {
                minWhite = k - cntBlack;
            }

            i++;
            j++;
        }

        cout << minWhite << endl;
    }

    return 0;
}


