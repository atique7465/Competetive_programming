#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, n, m;
ll mat[210][210];
ll mat1[210][210];
ll mat2[210][210];

ll sumRight(ll i, ll j, ll sum) {

    if (i < 1 || j > m) {
        return sum;
    }

    return mat1[i][j] = sumRight(i - 1, j + 1, sum + mat[i][j]);
}

ll sumLeft(ll i, ll j, ll sum) {

    if (i < 1 || j < 1) {
        return sum;
    }

    return mat2[i][j] = sumLeft(i - 1, j - 1, sum + mat[i][j]);
}

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        cin >> m;

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                cin >> mat[i][j];
            }
        }

        for (ll i = 1; i <= n; i++) {
            sumRight(i, 1, 0);
        }

        for (ll j = 2; j <= m; j++) {
            sumRight(n, j, 0);
        }

        for (ll j = 1; j <= m; j++) {
            sumLeft(n, j, 0);
        }

        for (ll i = 1; i < n; i++) {
            sumLeft(i, m, 0);
        }

        ll max = 0;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                if (mat1[i][j] + mat2[i][j] - mat[i][j] > max) {
                    max = mat1[i][j] + mat2[i][j] - mat[i][j];
                }
            }
        }

        cout << max << endl;

    }

    return 0;
}
