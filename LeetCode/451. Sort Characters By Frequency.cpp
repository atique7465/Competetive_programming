class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int>freq;
        for(int i = 0; i < s.size(); i++) freq[s[i]]++;
        
        vector<pair<char, int>>v;
        unordered_map<char, int>::iterator it;
        for(it = freq.begin(); it != freq.end(); it++)
            v.push_back({it->first, it->second});
        
        sort(v.begin(), v.end(), [](auto &p1, auto &p2){return p1.second > p2.second;});
        
        string res = "";
        for(int i = 0; i < v.size(); i++)
            for(int j = 0; j < v[i].second; j++) res+=v[i].first;
        
        return res;
    }
};