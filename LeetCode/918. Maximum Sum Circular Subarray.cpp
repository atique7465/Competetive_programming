class Solution_02 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0, sum = 0;
        for(int num:nums){
            curMax = max(curMax, 0) + num;
            maxSum = max(maxSum, curMax);
            curMin = min(curMin, 0) + num;
            minSum = min(minSum, curMin);
            sum += num;
        }
        return minSum == sum ? maxSum : max(maxSum, sum - minSum);
    }
};


class Solution_01 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxSuffix(n);
        maxSuffix[n-1] = nums[n-1];
        int suffixSum = maxSuffix[n-1];
        for(int i = n - 2; i >= 0; i--){
            suffixSum += nums[i];
            maxSuffix[i] = max(maxSuffix[i+1], suffixSum);
        } 

        int maxSum = nums[0], curSum = 0, specialSum = nums[0], prefixSum = 0;
        for(int i = 0; i < n; i++){
            curSum = max(curSum, 0) + nums[i];
            maxSum = max(maxSum, curSum);
            
            prefixSum += nums[i];
            if(i+1 < n)
               specialSum = max(specialSum, prefixSum + maxSuffix[i+1]);
        }

        return max(maxSum, specialSum);
    }
};