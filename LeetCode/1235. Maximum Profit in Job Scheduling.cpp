class Solution {
    unordered_map<int, int>dp;
    unordered_map<int, vector<int>> jobMap;
    vector<int> uniqueStarts;
    int job, nextStart;
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        set<int> ust;
        for(int i = 0; i < startTime.size(); i++){
            ust.insert(startTime[i]); jobMap[startTime[i]].push_back(i);
        }
        
        for(auto i : ust) uniqueStarts.push_back(i);
        
        return solve(uniqueStarts[0], endTime, profit);
    }
    
    int solve(int s, vector<int>& endTime, vector<int>& profit){
                
        if(dp.find(s) != dp.end()) return dp[s];
        
        int res = 0;
        if(s+1 <= uniqueStarts[uniqueStarts.size()-1]){
            nextStart = uniqueStarts[lower_bound(uniqueStarts.begin(), uniqueStarts.end(), s+1) - uniqueStarts.begin()];
            res = max(res, solve(nextStart, endTime, profit));
        }
        
        if(jobMap.find(s) != jobMap.end()){
            for(int j = 0; j < jobMap[s].size(); j++){
                job = jobMap[s][j];
                res = max(res, profit[job] + solve(endTime[job], endTime, profit));
            }
        }
        
        return dp[s] = res;
    }
};