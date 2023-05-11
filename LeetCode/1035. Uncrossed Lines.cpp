class Solution {
    vector<vector<int>> dp;
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(), vector<int>(nums2.size(), -1));
        return solve(0, 0, nums1, nums2);
    }

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        if(i >= nums1.size() || j >= nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        if(nums1[i] == nums2[j]) 
            res = max(res, 1 + solve(i+1, j+1, nums1, nums2));
        else
            res = max(res, max(solve(i+1, j, nums1, nums2), solve(i, j+1, nums1, nums2)));

        return dp[i][j] = res;
    }
};