class Solution {
    vector<pair<int, int>> players;
    vector<vector<int>> dp;
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        dp.resize(ages.size()+1, vector<int>(ages.size()+1, -1));
        for(int i = 0; i < ages.size(); i++) players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        return solve(0, -1, players, dp);
    }

    int solve(int curr, int prev, vector<pair<int, int>> &players, vector<vector<int>> &dp){
        if(curr >= players.size()) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];

        int res = 0;
        if(prev == -1 || players[prev].first == players[curr].first || players[prev].second <= players[curr].second)
           res = max(res, solve(curr + 1, curr, players, dp) + players[curr].second);
        
        return dp[curr][prev+1] = max(res, solve(curr + 1, prev, players, dp));
    }
};