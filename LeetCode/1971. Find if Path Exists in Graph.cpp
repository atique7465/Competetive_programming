class Solution {
    unordered_map<int, vector<int>> mp;
    vector<bool> visited;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited.resize(n, false);
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(source, destination);
    }

    bool dfs(int source, int dest){
            if(source == dest) return true;
            if(visited[source]) return false;
            for(int i = 0; i < mp[source].size(); i++){
                visited[source] = true;
                if(dfs(mp[source][i], dest)) return true;
            }
            return false;
    }
};