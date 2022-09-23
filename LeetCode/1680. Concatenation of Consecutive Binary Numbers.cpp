#include <bits/stdc++.h>

using namespace std;

/*
 [Recursion, vector, simulation]
 Accepted
 Runtime: 2454 ms
 Memory Usage: 294.1 MB
 */
class Solution_01 {

    int MOD = 1e9 + 7;

public:
    int concatenatedBinary(int n) {

        vector<int> v;

        for (int i = 1; i <= n; i++) {
            convert2Binary(i, v);
        }

        int res = 0;
        int ln = v.size();
        int pow = 1;
        for (int i = ln - 1; i >= 0; i--) {
            res += v[i] == 0 ? 0 : pow;
            res %= MOD;
            pow = (pow * 2) % MOD;
        }
        return res;
    }

public:
    void convert2Binary(int x, vector<int> &v) {

        if (x == 0) {
            return;
        }

        convert2Binary(x / 2, v);

        v.push_back(x % 2);
    }
};

/*
  [Recursion]
  Accepted
  Runtime: 882 ms
  Memory Usage: 6 MB
 */
class Solution_02 {

    int MOD = 1e9 + 7;
    int res = 0;

public:
    int concatenatedBinary(int n) {
        solve(n, -1);
        return res;
    }

public:
    void solve(int n, int pow) {

        if (n == 0) {
            return;
        }

        pow = d2bAndCalc(n, pow);

        solve(n - 1, pow);
    }

public:
    int d2bAndCalc(int x, int pow) {

        if (x == 0) {
            return pow;
        }

        pow = (pow == -1) ? 1 : ((pow * 2) % MOD);
        res = (x % 2 == 0) ? res : (res + pow) % MOD;

        pow = d2bAndCalc(x / 2, pow);

        return pow;
    }
};


/*
  Accepted [left shifting current sum with next number bit count & add the next number to the sum]
  Runtime: 187 ms
  Memory Usage: 6 MB
 */
class Solution {

    int MOD = 1e9 + 7;

public:
    int concatenatedBinary(int n) {

        long res = 0;

        for (int i = 1; i <= n; i++) {
            res = ((res << (int) (log2(i) + 1)) + i) % MOD;
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.concatenatedBinary(12);
}