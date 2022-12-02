class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> mp1; unordered_map<char, int> mp2;
        for(int i = 0; i < word1.size(); i++) mp1[word1[i]]++;
        for(int i = 0; i < word2.size(); i++) mp2[word2[i]]++;
        
        if(mp1.size() != mp2.size()) return false;
        
        for(auto const&[k,v]:mp1)
            if(mp2.find(k) == mp2.end()) return false;
        
        vector<int>v1; vector<int>v2;
        for(auto const&[k,v]:mp1) v1.push_back(v);
        for(auto const&[k,v]:mp2) v2.push_back(v);
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        for(int i = 0; i < v1.size(); i++)
            if(v1[i] != v2[i]) return false;
        
        return true;
    } 
};