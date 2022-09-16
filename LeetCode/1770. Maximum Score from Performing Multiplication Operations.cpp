class Solution {

    int n, m;
    vector<vector<int>> dp;
    vector<int> gNums, gMultipliers;

public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        gNums = nums;
        gMultipliers = multipliers;
        n = nums.size();
        m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, 0);
    }

public:
    int solve(int numsIdx, int multIdx) {

        if (multIdx >= m) {
            return 0;
        }

        if (dp[multIdx][numsIdx] != INT_MIN) {
            return dp[multIdx][numsIdx];
        }

        int left = solve(numsIdx + 1, multIdx + 1) + gNums[numsIdx] * gMultipliers[multIdx];
        int right = solve(numsIdx, multIdx + 1) + gNums[n - (multIdx - numsIdx) - 1] * gMultipliers[multIdx];

        return dp[multIdx][numsIdx] = max(left, right);
    }
};