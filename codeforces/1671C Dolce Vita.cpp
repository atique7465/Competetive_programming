#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main() {

    int t, n, x;

    cin >> t;
    while (t--) {
        cin >> n >> x;
        int price[n + 1];
        price[0] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> price[i];
        }

        sort(price, price + n + 1);

        ll curr_sum = 0;
        ll total_result = 0;
        if (price[1] <= x) {
            for (int i = 1; i <= n; i++) {
                int ck = 0;
                ll result = 0;
                curr_sum += price[i - 1];
                ll start = 0, end = x;
                while (start <= end) {
                    ll mid = (start + end) / 2;
                    ll calc = (x - curr_sum - ((i - 1) * mid));
                    if (calc >= (price[i] + mid)) {
                        if (mid == 0) {
                            ck = 1;
                        }
                        result = mid;
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }

                if (result == 0) {
                    if (ck == 1) {
                        total_result += result + 1;
                    }
                } else {
                    total_result += result + 1;
                }

                if (result == 0 && ck == 0) {
                    break;
                }
            }
        }

        cout << total_result << endl;
    }

    return 0;
}