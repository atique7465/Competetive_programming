class Solution {
    set<vector<int>> result;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> loc;
        solve(0, nums, loc);
        return vector(result.begin(), result.end());
    }

    void solve(int i, vector<int>& nums, vector<int> & loc){
        if(i >= nums.size()) {
          if(loc.size() >= 2) result.insert(loc);
          return;
        }

        if(loc.empty() || nums[i] >= loc[loc.size()-1]){
            loc.push_back(nums[i]);
            solve(i+1, nums, loc);
            loc.pop_back();
        }

        solve(i+1, nums, loc);
    }
};