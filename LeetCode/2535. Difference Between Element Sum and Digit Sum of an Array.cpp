class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0, digitSum = 0;
        for(int i = 0; i < nums.size(); i++){
            elementSum += nums[i];
            int val = nums[i];
            while(val > 0){
                digitSum += val % 10;
                val /= 10;
            }
        }
        
        return abs(elementSum - digitSum);
    }
};