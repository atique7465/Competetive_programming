#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dp[301][11];
    int len;
public:
    int minDifficulty(vector<int> &jobDifficulty, int d) {
        memset(dp, -1, sizeof(dp));
        len = jobDifficulty.size();
        if (len < d) return -1;
        return solve(0, d, jobDifficulty);
    }

    int solve(int i, int d, vector<int> &jobDifficulty) {

        if (dp[i][d] != -1) {
            return dp[i][d];
        }

        int res = INT_MAX;
        int mx = jobDifficulty[i];
        for (int j = i; j <= len - d; j++) {
            mx = max(mx, jobDifficulty[j]);
            res = d > 1 ? min(res, mx + solve(j + 1, d - 1, jobDifficulty)) : mx;
        }

        return dp[i][d] = res;
    }
};