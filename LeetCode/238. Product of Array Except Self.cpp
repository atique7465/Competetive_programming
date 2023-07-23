class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> res; 
 
        int f = 1;
        for(int i = 0; i < nums.size(); i++){
            res.push_back(f); f *= nums[i];
        }

        f = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            res[i] *= f; f *= nums[i];
        }

        return res;
    }
};