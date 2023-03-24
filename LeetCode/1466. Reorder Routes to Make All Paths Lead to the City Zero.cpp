class Solution {
    unordered_map<int, vector<pair<int, int>>> tree;
    vector<bool> vis;
    int res = 0;
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i; i < connections.size(); i++){
            tree[connections[i][0]].push_back({connections[i][1], 1});
            tree[connections[i][1]].push_back({connections[i][0], 0});
        }
        vis.resize(n, false);
        solve(0);
        return res;
    }
    
    void solve(int node){
        vis[node] = true;
        for(auto const&[next, dir]:tree[node]){
            if(!vis[next]){
                res += dir;
                solve(next);
            }
        }
    }
};