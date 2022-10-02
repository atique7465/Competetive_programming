#include <bits/stdc++.h>

using namespace std;

class Solution {
    int mod = 1e9 + 7;
    int dp[31][1001];
    int totalFace = 0;
    int totalDice = 0;
public:
    int numRollsToTarget(int n, int k, int target) {
        totalFace = k;
        totalDice = n;
        memset(dp, -1, sizeof dp);
        return solve(1, target);
    }

    int solve(int dice, int target) {

        if (target < 0) {
            return 0;
        }

        if (dice > totalDice) {
            if (target == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[dice][target] != -1) {
            return dp[dice][target];
        }

        int res = 0;
        for (int i = 1; i <= totalFace; i++) {
            res = (res + solve(dice + 1, target - i) % mod) % mod;
        }

        return dp[dice][target] = res;
    }
};

int main() {
    Solution s;
    cout << s.numRollsToTarget(30, 30, 500);
}