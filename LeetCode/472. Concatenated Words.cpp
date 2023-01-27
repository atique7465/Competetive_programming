class Solution {
   unordered_map<string, bool> mp;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int l1 = 30, l2 = 30;
        for(int i = 0; i < words.size(); i++) {
           mp[words[i]] = true;
           if(words[i].size() < l1) {
               l1 = words[i].size(); l2 = l1;
           }else if(words[i].size() < l2) l2 = words[i].size();
        }

        vector<string> res;
        for(int i = 0; i < words.size(); i++){
            vector<vector<int>> dp(words[i].size(), vector<int>(words[i].size(), -1));
            if(words[i].size() >= l1 + l2 && isConcatenated(0, words[i], dp)) res.push_back(words[i]);
        }

        return res;
    }

    bool isConcatenated(int i, string &s, vector<vector<int>> &dp){
         for(int j = i; j < s.size(); j++){
             if(dp[i][j]!=-1){
               return dp[i][j] ? true : false;
             }else if(s.substr(i, j-i+1) != s && mp.find(s.substr(i, j-i+1)) != mp.end()){
                dp[i][j] = j+1 == s.size() ? 1 : isConcatenated(j+1, s, dp) ? 1 : 0;
                if(dp[i][j]) return true;
             }else dp[i][j] = 0;
         }

         return false;
    }
}; 