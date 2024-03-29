class Solution {
    vector<vector<int>>dp;
public:
    int uniquePaths(int m, int n) {
        dp.resize(101, vector<int>(101,-1));
        return solve(0,0,m,n);
    }
    
    int solve(int i, int j, int m, int n){
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = solve(i+1, j, m, n) + solve(i, j+1, m, n);
    }
};