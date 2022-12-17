class Solution {
    vector<vector<int>> dp;
public:
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1, vector<int>(2,-1)); 
        return solve(0, 1, prices);
    }

    int solve(int i, int buy, vector<int>& prices){
        if(i >= prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy] =  max(0, max(solve(i+1, 0, prices) - prices[i], solve(i+1, 1, prices)));
        }else{
            return dp[i][buy] =  max(0, max(solve(i+1, 1, prices) + prices[i], solve(i+1, 0, prices)));
        }
    }
};