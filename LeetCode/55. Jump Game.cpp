class Solution_01 {
    //just iterate and update the maximal index that can be reached
public:
    bool canJump(vector<int>& nums) {
        bool res = false;
        int mx = 0;
        for(int i = 0; i < nums.size() && i <= mx; i++){
            mx = max(mx, i + nums[i]);
            if(mx >= nums.size()-1){
                res = true;
                break;
            }
        }
        
        return res;
    }
};

class Solution_02 {
    vector<int>dp;
public:
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        return solve(0, nums);
    }
    
    bool solve(int i, vector<int>& nums){
        if(i == nums.size() - 1) return true;
        if(i >= nums.size()) return false;
        if(dp[i] != -1) return dp[i];
        bool res = false;
        for(int j = 1; j <= nums[i]; j++){
            res = res | solve(i+j, nums);
            if(res) break;
        }
        return dp[i] = res;
    }
};