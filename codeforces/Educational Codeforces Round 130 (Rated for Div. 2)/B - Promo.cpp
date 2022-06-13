#includebitsstdc++.h

#define ll long long int
using namespace std;
ll n, q, val, x, y;

int main() {
    cin  n;
    cin  q;

    vectorll v;
    v.push_back(0);
    for (ll i = 1; i = n; i++) {
        cin  val;
        v.push_back(val);
    }

    sort(v.begin(), v.end());

    for (ll i = 1; i = n; i++) {
        v[i] += v[i - 1];
    }

    while (q--) {
        cin  x;
        cin  y;
        cout  v[n - x + y] - v[n - x]  endl;
    }

    return 0;
}


