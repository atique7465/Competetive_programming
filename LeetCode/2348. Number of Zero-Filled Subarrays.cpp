class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = 0;
        while(j < nums.size()){
            while(j < nums.size() && nums[j]==0) j++;
            if(j > i){
                long long n = j-i;
                ans += (n*(n+1))/2;
            }
            j++; i = j;
        }
        return ans;
    }
};