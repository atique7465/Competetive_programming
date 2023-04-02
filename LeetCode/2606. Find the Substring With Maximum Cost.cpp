class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> mp;
        for(int i = 0; i < chars.size(); i++) mp[chars[i]] = vals[i];
        vector<int> v;
        for(int i = 0; i < s.size(); i++) v.push_back(mp.find(s[i]) != mp.end() ? mp[s[i]] : (s[i] - 'a' + 1));
        int loc = 0, res = 0;
        for(int val:v){
            loc += val;
            res = max(res, loc);
            if(loc < 0) loc = 0;
        }
        return res;
    }
};