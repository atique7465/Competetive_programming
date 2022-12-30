class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        dfs(0, graph, path);
        return res;
    }

    void dfs(int i, vector<vector<int>>& graph, vector<int> &path){
        if(i == graph.size()-1){
            res.push_back(path);
            return;
        }
        for(int j = 0; j < graph[i].size(); j++){
            path.push_back(graph[i][j]);
            dfs(graph[i][j], graph, path);
            path.pop_back();
        }
    }
};