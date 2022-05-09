#include <bits/stdc++.h>

#define ll long long int
using namespace std;

ll t, i, n, triangleCnt = 0, currLine = 1;
vector<ll> trianglesByLines;
ll lineTypeCnt[4];

long long int solve();

void init() {
    while (triangleCnt <= 1000000000) {
        switch (currLine) {
            case 1:
                triangleCnt += 2 * (lineTypeCnt[2] + lineTypeCnt[3]);
                lineTypeCnt[1]++;
                break;
            case 2:
                triangleCnt += 2 * (lineTypeCnt[1] + lineTypeCnt[3]);
                lineTypeCnt[2]++;
                break;
            case 3:
                triangleCnt += 2 * (lineTypeCnt[1] + lineTypeCnt[2]);
                lineTypeCnt[3]++;
                break;
        }
        trianglesByLines.push_back(triangleCnt);
        currLine = (currLine % 3) + 1;
    }
}

ll solve() {
    ll start = 0, end = trianglesByLines.size() - 1, result = 0, mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;

        if (trianglesByLines[mid] == n) {
            result = mid;
            break;
        } else if (trianglesByLines[mid] > n) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return result + 1;
}

int main() {

    init();

    cin >> t;

    while (t--) {
        cin >> n;
        cout << solve() << endl;
    }

    return 0;
}
