class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2, vector<int>());
        unordered_set<int> set1, set2;
        for(int num:nums1) set1.insert(num);
        for(int num:nums2) set2.insert(num);
        for(int num:set1) if(set2.count(num) == 0) res[0].push_back(num);
        for(int num:set2) if(set1.count(num) == 0) res[1].push_back(num);
        return res;
    }
};