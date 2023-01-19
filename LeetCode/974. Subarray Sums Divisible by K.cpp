class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0, prefixMod = 0;
        unordered_map<int,int> modGroup;
        modGroup[0] = 1;
        for(int num:nums){
           prefixMod = (prefixMod + num % k + k) % k;
           result += modGroup.find(prefixMod) != modGroup.end() ? modGroup[prefixMod] : 0;
           modGroup[prefixMod]++;
        }
        return result;
    }
};