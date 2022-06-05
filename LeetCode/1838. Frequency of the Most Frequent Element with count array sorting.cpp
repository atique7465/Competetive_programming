class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int ln = nums.size();
        
        ///sorting part started using count array
        int arr[100010];
        memset(arr, 0, sizeof(arr));
        
        for(int i = 0; i < ln; i++){
            arr[nums[i]]++;
        }
        
        vector<int> sortedNums;
        
        for(int i = 0; i < 100010; i++){
            if(arr[i] > 0){
                int cnt = arr[i];
                while(cnt--){
                    sortedNums.push_back(i);
                }
            }
        }
        ///sorting part finished using count array
        
        ///two pointer approach
        int result = 1;
        
        int j = ln - 1;
        long long int sum = 0L;
        for(int i = ln - 1; i >= 0; i--){
            
            if(j >= i){
                j = i;
                sum = sortedNums[i];
            }
                        
            while(j - 1 >=0 && ((1L * sortedNums[i] * (i - j + 2)) - (sum + sortedNums[j-1]) <= k)){
                j--;
                sum += sortedNums[j];
            }
            
            if(i - j + 1 > result){
                result = i - j + 1;
            }
            
            sum -= sortedNums[i];
        }
        
        return result;
    }
};