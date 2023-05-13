class Solution {
    vector<int> dp;
    int mod = 1e9+7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high + 1, -1);
        int res = 0;
        for(int i = high; i >= low; i--) res = (res + solve(i, low, zero, one)) % mod;
        return res;
    }

    int solve(int curr, int low, int zero, int one){
        
        if(curr < min(zero, one)) return 0;
        if(dp[curr] != -1) return dp[curr];

        int zeroRes = (curr == zero) ? 1 : solve(curr - zero, low, zero, one);
        int oneRes = (curr == one) ? 1 : solve(curr - one, low, zero, one);

        return dp[curr] = (zeroRes + oneRes) % mod;
    }
};