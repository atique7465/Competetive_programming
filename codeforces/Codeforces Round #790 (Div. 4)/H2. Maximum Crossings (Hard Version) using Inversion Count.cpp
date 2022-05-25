#include<bits/stdc++.h>

#define ll long long int
using namespace std;

ll merge(ll v[], ll l, ll mid, ll r) {

    ll invCnt = 0;
    vector<ll> tmp;

    ll i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (v[i] >= v[j]) {
            tmp.push_back(v[j]);
            j++;
            invCnt += mid - i + 1;
        } else {
            tmp.push_back(v[i]);
            i++;
        }
    }

    while (i <= mid) {
        tmp.push_back(v[i]);
        i++;
    }

    while (j <= r) {
        tmp.push_back(v[j]);
        j++;
    }

    ll p = 0, q = l;
    while (p < tmp.size()) {
        v[q] = tmp[p];
        p++;
        q++;
    }

    return invCnt;
}

ll countInversionUsingMergeSort(ll v[], ll l, ll r) {

    ll invCnt = 0;
    if (l < r) {
        ll mid = (l + r) / 2;
        invCnt += countInversionUsingMergeSort(v, l, mid);
        invCnt += countInversionUsingMergeSort(v, mid + 1, r);
        invCnt += merge(v, l, mid, r);
    }

    return invCnt;
}

int main() {
    ll t, n, x;
    ll v[200010];
    cin >> t;

    while (t--) {
        cin >> n;

        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }

        cout << countInversionUsingMergeSort(v, 0, n - 1) << endl;
    }

    return 0;
}

