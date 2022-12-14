class Solution {
    vector<int>dp;
public:
    int rob(vector<int>& nums) {
        dp.resize(110, -1);
        return solve(0, nums);
    }

    int solve(int i, vector<int>& nums){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i]+solve(i+2, nums), solve(i+1, nums));
    }
};