class Solution {
public:
    int partitionString(string s) {
        int i = 0, j = 0, cnt = 0;
        while(i < s.size()){
            j = i;
            unordered_map<char, bool> mp;
            while(j < s.size() && mp.find(s[j]) == mp.end()){
                mp[s[j]] = true;
                j++;
            }
            cnt++;
            i = j;
        }
        return cnt;
    }
};