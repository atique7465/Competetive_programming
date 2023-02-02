class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> mp;
        for(int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            mp[order[i]] = ch;
        }

        vector<string> words2;
        for(string s:words){
            string s1 = s;
            for(int i = 0; i < s.size(); i++) s1[i] = mp[s[i]];
            words2.push_back(s1);
        }

        // for(string s:words2) cout<<s<<endl;    
        
        bool ans = true;
        for(int i = 1; i < words2.size(); i++) if(words2[i] < words2[i-1]) { ans = false; break; }

        return ans;
    }
};