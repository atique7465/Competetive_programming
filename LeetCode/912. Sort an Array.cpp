class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> mp;
        for(int num:nums) mp[num]++;
        vector<int>res;
        for(auto const&[k,v]:mp) {
            int cnt = v;
            while(cnt--) res.push_back(k);
        }
        return res;
    }
};