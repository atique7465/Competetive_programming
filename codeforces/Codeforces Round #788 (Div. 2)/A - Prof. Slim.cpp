/**
 *@author atiQue
 *@since 5/6/2022 8:03 PM
*/

#include <bits/stdc++.h>

using namespace std;
int t, n;

int main() {

    cin >> t;
    while (t--) {
        cin >> n;
        int arr[n];
        int ng = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] < 0) {
                ng++;
            }
        }

        bool ck1 = true;
        for (int i = 0; i < ng - 1; i++) {
            if (abs(arr[i]) < abs(arr[i + 1])) {
                ck1 = false;
            }
        }

        bool ck2 = true;
        for (int i = ng; i < n - 1; i++) {
            if (abs(arr[i]) > abs(arr[i + 1])) {
                ck2 = false;
            }
        }

        if (ck1 && ck2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}