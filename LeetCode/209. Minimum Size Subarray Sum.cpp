class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, sum = nums[0], minLength = INT_MAX;
        while(start <= end && end < nums.size()){
            if(sum>=target){
                minLength = min(minLength, end - start + 1);
                sum-=nums[start++];
            }else{
                end++;
                if(end < nums.size()) sum += nums[end];
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};