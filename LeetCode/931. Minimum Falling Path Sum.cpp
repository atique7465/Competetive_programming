class Solution {
    vector<vector<int>> dp;
    int r,c,res=INT_MAX,inf = 99999;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        r = matrix.size(); c = matrix[0].size();
        dp.resize(110, vector<int>(110, -1));
        for(int j = 0; j < r; j++) res = min(res, solve(0,j,matrix));
        return res;
    }
    
    int solve(int i, int j, vector<vector<int>>& matrix){
        if(i == r-1 && (j >=0 && j < c)) return matrix[i][j];
        if(i < 0 || j < 0 || i >= r || j >= c) return inf;  
        if(dp[i][j] != -1) return dp[i][j];
        int res = solve(i+1, j-1, matrix);
        res = min(res, solve(i+1, j, matrix));
        res = min(res, solve(i+1, j+1, matrix));
        return dp[i][j] = matrix[i][j] + res;
    }
};