class Solution_01 {
    vector<vector<int>> result;
    int len;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>status(len = nums.size(), 0); vector<int> bin;
        solve(nums, status, bin);
        return result;
    }
    
    void solve(vector<int>& nums, vector<int>& status, vector<int>& bin){
        if(bin.size() == len){
            result.push_back(bin);
        }
        
        for(int i = 0; i < len; i++){
            if(!status[i]){
                bin.push_back(nums[i]);
                status[i] = 1;
                solve(nums, status, bin);
                status[i] = 0;
                bin.pop_back();
            }
        }
    }
};


class Solution_02 {
    vector<vector<int>> result;
    int len;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        solve(0, nums);
        return result;
    }
    
    void solve(int start, vector<int>& nums){
        if(start >= len){
            result.push_back(nums);
            return;
        }
        
        for(int i = start; i < len; i++){
            swap(nums[start], nums[i]);
            solve(start+1, nums);
            swap(nums[start], nums[i]);
        }
    }
};

//Ref: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/