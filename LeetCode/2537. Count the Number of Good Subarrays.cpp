class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long int result = 0, pair = 0;
        int i = 0,  j = 0;
        while(i < nums.size() && j < nums.size()){
            pair += freq[nums[j]];
            freq[nums[j]]++;
            while(i < j && pair >= k){
                result += nums.size() - j;
                freq[nums[i]]--;
                pair -= freq[nums[i]];
                i++;
            }
            j++;
        }
        return result;
    }
};