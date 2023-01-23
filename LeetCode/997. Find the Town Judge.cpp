class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> tree(n+1);
        for(int i = 0; i < trust.size(); i++)
            tree[trust[i][0]].push_back(trust[i][1]);
        
        int tj = 0;
        for(int i = 1; i <= n; i++) {
            if(tree[i].size() == 0){
                tj = i;
                break;
            }
        }

        if(tj == 0) return -1;
        
        vector<int>v(n+1, 0);
        for(int i = 0; i < trust.size(); i++)
            if(trust[i][1] == tj) v[trust[i][0]] = 1;
        
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(i != tj && v[i] == 0) cnt++;
        
        return cnt == 0 ? tj : -1;
    }
};