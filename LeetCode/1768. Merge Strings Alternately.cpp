class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int sz = min(word1.size(), word2.size());
        string res = "";
        for(int i = 0; i < sz; i++) {
            res += word1[i];
            res += word2[i];
        }

        if(word1.size() > sz) 
            for(int i = sz; i < word1.size(); i++) res += word1[i];
        else 
            for(int i = sz; i < word2.size(); i++) res += word2[i];
        
        return res;
    }
};