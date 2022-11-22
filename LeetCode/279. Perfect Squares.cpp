class Solution_01 {
public:
    int numSquares(int n) {
        vector<int> v(n+1, INT_MAX); v[0]=0;
        for(int i = 1; i <=n; i++){
            for(int j = 1; j*j<=i; j++){
                v[i] = min(v[i], v[i-j*j] + 1);
            }
        }
        return v[n];
    }
};

class Solution_02 {
    vector<int>dp;
    vector<int>ps;
    int inf = INT_MAX;
public:
    int numSquares(int n) {
        dp.resize(10010, -1);
        for(int i = 1; i*i <= 10010; i++) ps.push_back(i*i);
        return solve(n);
    }
    
    int solve(int n){
        
        if(dp[n] != -1) return dp[n];
        
        int pos = lower_bound(ps.begin(), ps.end(), n) - ps.begin();
        if(ps[pos] == n) return 1;
        if(ps[pos] > n) pos--;
        if(ps[pos] <= 3) return n;
        
        int res = inf;
        for(int i=pos; i>=1; i--) res = min(res, solve(n-ps[i]));
        
        return dp[n] = res == inf ? res : res + 1;
    }
};