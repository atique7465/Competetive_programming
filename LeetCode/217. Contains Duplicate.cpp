class Solution {
public:
    bool containsDuplicate_01(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }

    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int i:nums){
            if(mp.find(i) == mp.end()) mp[i] = true;
            else return true;
        }
        return false;
    }
};