class Solution {
    int top;
    vector<int> dp;
public:
    int climbStairs(int n) {
        top=n; dp.resize(n+10,-1);
        return solve(1) + solve(2);
  
    }
    
    int solve(int i){
        if(i==top)
            return 1;
        if(i>top) 
            return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        return dp[i]= solve(i+1) + solve(i+2);

    }
};