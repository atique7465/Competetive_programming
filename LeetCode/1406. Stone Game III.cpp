class Solution {
    vector<int> dp; 
    int inf = 1000000000;
public:
    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size(), inf);
        int val = solve(0, stoneValue);
        return val > 0 ? "Alice" : val < 0 ? "Bob" : "Tie";
    }

    int solve(int i, vector<int>& stoneValue){

        if(i == stoneValue.size()) return 0;

        if(dp[i] != inf) return dp[i];

        dp[i] = stoneValue[i] - solve(i+1, stoneValue);
        if(i+2 <= stoneValue.size()) dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] - solve(i+2, stoneValue));
        if(i+3 <= stoneValue.size()) dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i + 2] - solve(i+3, stoneValue));

        return dp[i];
    }
};