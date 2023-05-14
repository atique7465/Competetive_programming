class Solution {
    vector<int> dp;
public:
    int maxScore(vector<int>& nums) {
        dp.resize(1 << nums.size(), -1);
        return solve(0, 0, nums);
    }

    int solve(int pick, int mask, vector<int>& nums){
        if(pick * 2 == nums.size()) return 0;
        if(dp[mask] != -1) return dp[mask];

        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(((mask >> i) & 1) || ((mask >> j) & 1)) continue;
                int newMask = mask | (1 << i) | (1 << j);
                res = max(res, (pick + 1) * __gcd(nums[i], nums[j]) + solve(pick + 1, newMask, nums));
            }
        }

        return dp[mask] = res;
    }
};