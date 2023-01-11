class Solution {
    int minSec = 0;
    vector<vector<int>> tree;
    vector<bool> visited;
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        tree.resize(n, vector<int>());
        visited.resize(n, false);
        for(int i = 0; i < edges.size(); i++){ 
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        calcMinSec(0, hasApple);
        return minSec;
    }

    bool calcMinSec(int i, vector<bool>& hasApple){
        visited[i]=true;
        bool has = false;

        for(int j = 0; j < tree[i].size(); j++){
            if(!visited[tree[i][j]]) has |= calcMinSec(tree[i][j], hasApple);
        } 

        if(has || hasApple[i]){
           if(i != 0) minSec += 2;
           has = true;
        } 
        return has;
    }
};