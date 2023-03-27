class Solution {
    vector<vector<int>> dp;
    int r,c;
public:
    int minPathSum(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        dp.resize(r, vector<int>(c, -1));
        return solve(0, 0, grid);
    }

    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= r || j >= c) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = grid[i][j];
        if(i != r - 1 || j != c - 1)
           ans += min(solve(i+1, j, grid), solve(i, j+1, grid));
        return dp[i][j] = ans;
    }
};