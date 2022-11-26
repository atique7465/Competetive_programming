class Solution {
    unordered_map<int, int>dp;
    unordered_map<int, vector<int>> jobMap;
    vector<int> uniqueStarts;
    unordered_map<int, int> uniqueStartIdx;
    int job;
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        set<int> ust;
        for(int i = 0; i < startTime.size(); i++){
            ust.insert(startTime[i]);
            jobMap[startTime[i]].push_back(i);
        }
        
        for(int i = 0; i < endTime.size(); i++) ust.insert(endTime[i]);
        
        int idx = 0;
        for(auto i : ust){
            uniqueStarts.push_back(i);
            uniqueStartIdx[i] = idx++;
        }
        
        return solve(uniqueStarts[0], endTime, profit);
    }
    
    int solve(int s, vector<int>& endTime, vector<int>& profit){
                
        if(dp.find(s) != dp.end()) return dp[s];
        
        int res = 0;
        if(uniqueStartIdx[s]+1 < uniqueStarts.size()){
            res = max(res, solve(uniqueStarts[uniqueStartIdx[s]+1], endTime, profit));
        }
        
        for(int j = 0; j < jobMap[s].size(); j++){
            job = jobMap[s][j];
            res = max(res, profit[job] + solve(endTime[job], endTime, profit));
        }
        
        return dp[s] = res;
    }
};