#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int i = 1, j = n - 2;
        int p1 = 0, p2 = 0;
        while (i <= j && !(p1 && p2)) {

            if (arr[i] == arr[i - 1]) {
                p1 = 1;
            } else {
                i++;
            }

            if (arr[j] == arr[j + 1]) {
                p2 = 1;
            } else {
                j--;
            }
        }

        if (j > i) {
            cout << j - i;
        } else if (j == i) {
            cout << 1;
        } else {
            cout << 0;
        }
        cout << endl;

    }

    return 0;
}
