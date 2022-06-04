class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<long long int> cumSum;
        
        int ln = nums.size();
        long long int sum = 0;
        for(int i = 0; i<ln; i++){
            sum += nums[i]; 
            cumSum.push_back(sum);
        }

        int result = 1;
        
        for(int i = 1; i<ln; i++){
            int start = 0, end = i-1;
            
            while(start <= end){
                int mid = (start + end) / 2;
                
                long long int mult = 1L * nums[i] * (i-mid);
                long long int sum = cumSum[i-1] - (mid - 1 < 0 ? 0 : cumSum[mid - 1]);
                if(mult - sum <= k){
                    end = mid - 1;
                    if(i - mid + 1 > result){
                        result = i - mid + 1;
                    }
                }else if(mult - sum > k){
                    start = mid + 1;
                }else{
                    if(i - mid + 1 > result){
                        result = i - mid + 1;
                    }
                }
            } 
        }
        
        return result;
    }
};