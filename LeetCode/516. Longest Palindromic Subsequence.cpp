class Solution {
    vector<vector<int>> dp;
    int ans;
public:
    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return solve(0, s.size() - 1, s);
    }

    int solve(int i, int j, string &s){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(s[i] == s[j]) ans = 2 + solve(i+1, j-1, s);
        else {
            ans = max(ans, solve(i+1, j, s));
            ans = max(ans, solve(i, j-1, s));
        }

        return dp[i][j] = ans;
    }
};