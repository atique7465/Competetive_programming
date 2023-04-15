class Solution {
    vector<vector<int>> dp;
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp.resize(piles.size(), vector<int>(k+1, -1));

        for(int i = 0; i < piles.size(); i++)
            for(int j = 1; j < piles[i].size(); j++)
               piles[i][j] += piles[i][j-1];

        return solve(0, k, piles);
    }

    int solve(int i, int k, vector<vector<int>>& piles){
        if(i >= piles.size() || k <= 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int ans = solve(i+1, k, piles);
        for(int j = 0; j < k && j < piles[i].size(); j++)
            ans = max(ans, piles[i][j] + solve(i+1, k - j - 1, piles));

        return dp[i][k] = ans;
    }

};