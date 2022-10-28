class Solution {
    int len;
    vector<string> result;
    unordered_map<char, string> mp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };                

public:
    vector<string> letterCombinations(string digits) {
        len = digits.size();
        string s = "";
        makeString(s, 0, digits);
        return result;
    }
    
    void makeString(string &curr, int i, string &digits){
                
        if(i >= len && curr != ""){
            result.push_back(curr);
            return;
        }
        
        for(int j = 0; j < mp[digits[i]].size(); j++){
            curr.push_back(mp[digits[i]][j]);
            makeString(curr, i + 1, digits);
            curr.pop_back();
        }
    }
};