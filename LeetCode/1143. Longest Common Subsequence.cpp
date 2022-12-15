class Solution {
    vector<vector<int>>dp;
public:
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size()+1, vector<int>(text2.size()+1, -1));
        return solve(0, 0, text1, text2);
    }

    int solve(int i, int j, string &text1, string &text2){
        if(i >= text1.size() || j >= text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int res = 0;
        if(text1[i]==text2[j])
            res = 1 + max(res, solve(i+1, j+1, text1, text2));
        else 
            res = max(res, max(solve(i+1, j, text1, text2), solve(i, j+1, text1, text2)));

        return dp[i][j] = res;
    }
};