class Solution {
    vector<vector<int>> tree;
    vector<bool> visited;
    vector<int>ans;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n, 0);
        visited.resize(n, false);
        tree.resize(n, vector<int>());
        for(int i = 0; i < edges.size(); i++){
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, tree, labels);
        return ans;
    }

    vector<int> dfs(int i, vector<vector<int>>& tree, string &labels){
        visited[i]=true;
        vector<int> mp(26, 0); mp[labels[i]-'a']=1;
        for(int j = 0; j < tree[i].size(); j++){
            if(!visited[tree[i][j]]){
                vector<int> loc = dfs(tree[i][j], tree, labels);
                for(int k = 0; k < loc.size(); k++) mp[k]+=loc[k];
            }
        }
        ans[i] = mp[labels[i]-'a'];
        return mp;
    }
};