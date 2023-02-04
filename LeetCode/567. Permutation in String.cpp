class Solution {
    unordered_map<char, int> s1Freq;
    unordered_map<char, int> s2Freq;
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        for(char ch:s1) s1Freq[ch]++;
        for(int i = 0; i < s1.size(); i++) s2Freq[s2[i]]++;
        int i = 0, j = s1.size()-1;
        while(j < s2.size()){
            if(checkIfContains()) return true;
            s2Freq[s2[i]]--; 
            i++;
            j++; 
            if(j < s2.size()) s2Freq[s2[j]]++;
        }

        return false;
    }

    bool checkIfContains(){
        for(auto const[k,v]:s1Freq){
            if(s2Freq.find(k)==s2Freq.end() || s2Freq[k] != v) 
            return false;
        }
        return true;
    }
};