class Solution {
    vector<int> dp;
    int mod = 1e9+7;
public:
    int numberOfArrays(string s, int k) {
        dp.resize(s.size(), -1);
        return solve(0, s, k);   
    }

    int solve(int start, string &s, int k){
        if(start >= s.size()) return 1;
        if(dp[start] != -1) return dp[start];

        int ans = 0; long long num = 0;
        if(s[start] != '0'){
            for(int end = start; end < s.size(); end++){
                num = num * 10 + s[end] - '0';
                if(num > k) break;
                ans = (ans + solve(end+1, s, k)) % mod;
            }
        }

        return dp[start] = ans; 
    }
};