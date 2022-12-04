class Solution_02_bitmasking {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int totSubs = 1 << nums.size();
        vector<vector<int>> res(totSubs);
        
        for(int i = 0; i < totSubs; i++){
            for(int j = 0; j < nums.size(); j++){
                if((i >> j) & 1) res[i].push_back(nums[j]);
            }
        }
        
        return res;   
    }
};


class Solution_01_backtracking {
    vector<vector<int>> res = {{}};
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(0, curr, nums);
        return res;   
    }
    
    void solve(int i, vector<int>& curr, vector<int>& nums){
        if(i >= nums.size()) return;
        curr.push_back(nums[i]);
        res.push_back(curr);
        solve(i+1, curr, nums);
        curr.pop_back();
        solve(i+1, curr, nums);
    }
};