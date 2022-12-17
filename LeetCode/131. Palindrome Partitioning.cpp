class Solution {
    vector<vector<string>> result;
    vector<string> curr;
    vector<vector<bool>> dp;
public:
    vector<vector<string>> partition(string s) {
       dp.resize(s.size(), vector<bool>(s.size(), false));
       solve(0, s);
       return result;
    }

    void solve(int start, string &s){
        if(start >= s.size()) {result.push_back(curr); return;};
        for(int end = start; end < s.size(); end++){
            if(s[start]==s[end] && (end-start<=2 || dp[start+1][end-1])){
               dp[start][end]=true;
               curr.push_back(s.substr(start, end-start+1));
               solve(end+1, s);
               curr.pop_back();
            }
        }
    }
};