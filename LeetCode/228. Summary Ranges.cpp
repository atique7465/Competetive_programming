class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, j = 0;
        while(j < nums.size()){
            while(j+1 < nums.size() && nums[j+1] == nums[j]+1) j++;
            string s = "";
            if(i < j)
                s += to_string(nums[i]) + "->" + to_string(nums[j]);
            else 
                s += to_string(nums[j]);
            res.push_back(s);
            j++; i = j;
        }
        return res;
    }
};