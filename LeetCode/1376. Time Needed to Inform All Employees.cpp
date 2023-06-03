class Solution {
    vector<vector<int>> tree;
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        tree.resize(n, vector<int>());
        for(int i = 0; i < n; i++) if(manager[i] != -1) tree[manager[i]].push_back(i);
        return solve(headID, informTime);
    }

    int solve(int head, vector<int>& informTime){
        int res = 0;
        for(int next:tree[head]) res = max(res, informTime[head] + solve(next, informTime));
        return res;
    }
};