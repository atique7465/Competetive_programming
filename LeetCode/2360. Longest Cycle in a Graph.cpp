class Solution {
    vector<bool>visited;
    int ans = -1;
public:
    int longestCycle(vector<int>& edges) {
        visited.resize(edges.size(), false);
        for(int i = 0; i < edges.size(); i++){
            if(!visited[i]){
                unordered_map<int, int> dist; dist[i] = 0;
                dfs(i, edges, dist);
            }
        }
        return ans;
    }

    void dfs(int i, vector<int>& edges, unordered_map<int, int> &dist){
        visited[i] = true;
        int next = edges[i];
        if(next != -1 && !visited[next]){
            dist[next] = dist[i] + 1;
            dfs(next, edges, dist);
        }else if(next != -1 && dist.find(next) != dist.end()){
            ans = max(ans, dist[i] - dist[next] + 1);
        }
    }
};