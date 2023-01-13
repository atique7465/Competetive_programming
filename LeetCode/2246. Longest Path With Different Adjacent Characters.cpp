class Solution {
    vector<vector<int>> tree;
    int LongestPath = 1;
public:
    int longestPath(vector<int>& parent, string s) {
        tree.resize(parent.size(), vector<int>());
        for(int i = 1; i < parent.size(); i++) tree[parent[i]].push_back(i);
        dfs(0, tree, s);
        return LongestPath;
    }

    int dfs(int i, vector<vector<int>> &tree, string &s){
        int longPath1 = 0, longPath2 = 0;

        for(int child : tree[i]){
            int longFromChild = dfs(child, tree, s);
            if(s[i]==s[child]) continue;
            if(longFromChild > longPath1){
                longPath2 = longPath1;
                longPath1 = longFromChild;
            }else if(longFromChild > longPath2){
                longPath2 = longFromChild;
            }
        }
        
        LongestPath = max(LongestPath, longPath1 + longPath2 + 1);
        return longPath1 + 1;
    }
};