class Solution {
    vector<long long> dp;
public:
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(), -1);
        return solve(0, questions);
    }

    long long solve(int i, vector<vector<int>>& questions){
        if(i >= questions.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        long long res = questions[i][0] + solve(i+questions[i][1]+1, questions);
        res = max(res, solve(i+1, questions));

        return dp[i] = res;
    }
};