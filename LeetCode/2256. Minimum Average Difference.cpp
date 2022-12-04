class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        int n = nums.size();
        long long sumFromStart = 0, sumFromEnd = 0;
        for(int i = 0; i < nums.size(); i++) sumFromEnd += nums[i];
        
        long long minDiff = INT_MAX, leftAvg, rightAvg, diff; int minIdx = 0;
        for(int i = 0; i < nums.size(); i++){
            sumFromStart += nums[i];
            sumFromEnd -= nums[i];
            leftAvg = sumFromStart / (i+1);
            rightAvg = i == n-1 ? 0 : sumFromEnd / (n - i - 1);
            diff = abs(leftAvg - rightAvg);
            if(diff < minDiff){
                minDiff = diff;
                minIdx = i;  
            } 
        }
        
        return minIdx;
    }
};