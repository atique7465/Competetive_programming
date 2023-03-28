class Solution {
    vector<int> dp;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), -1);
        return solve(0, days, costs);
    }

    int solve(int i, vector<int>& days, vector<int>& costs){
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int d = 0; d < 3; d++){
            int canGo = days[i] + (d == 0 ? 1 : d == 1 ? 7 : 30) - 1;
            int j = i;
            while(j < days.size() && days[j] <= canGo) j++;
            ans = min(ans, costs[d] + (j < days.size() ? solve(j, days, costs) : 0));
        }
        return dp[i] = ans;
    }
};