class Solution {
    unordered_map<char, int> pMap;
    unordered_map<char, int> sMap;
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()<p.size()) return res;
        
        for(char c:p) pMap[c]++;

        for(int i = 0; i < p.size(); i++) sMap[s[i]]++;

        int i = 0, j = p.size()-1;
        while(j < s.size()){
            if(isAnagram())
              res.push_back(i);
            sMap[s[i++]]--;
            j++;
            sMap[s[j]]++;
        }

        return res;
    }
    
    bool isAnagram(){
        for(auto const&[k,v]:pMap){
            if(sMap.find(k) == sMap.end() || v != sMap[k]) return false;
        }
        return true;
    }
};