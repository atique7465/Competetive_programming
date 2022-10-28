class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        
        int len = strs.size();
        for(int i = 0; i < len; i++) mp[getHash(strs[i])].push_back(strs[i]);
        
        for(auto const&[k,v] : mp) result.push_back(v);
        
        return result;
    }
    
    
    string getHash(string &s){
        
        int arr[26];
        memset(arr, 0, sizeof(arr));
        
        int len = s.size();
        for(int i = 0; i < len; i++) arr[s[i] - 'a']++;
        
        string hash = "";
        for(int i = 0; i < 26; i++){
            if(arr[i] > 0) {
                hash.push_back('a' + i);
                hash.push_back('0' + arr[i]);
            }
        }
        
        return hash;
    }
    
};