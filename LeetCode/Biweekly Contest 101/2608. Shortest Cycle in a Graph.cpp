class Solution_01 {
    vector<vector<int>> graph;
    int mn = INT_MAX;
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        graph.resize(n, vector<int>());
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++){
           vector<bool> vis(n, false); unordered_map<int, int> dist; dist[i] = 0;
           solve(i, -1, vis, dist);
        }
        return mn == INT_MAX ? -1 : mn;
    }
    
    void solve(int node, int root, vector<bool> &vis, unordered_map<int, int> &dist){
        vis[node] = true;
        for(int next:graph[node]){
            if(!vis[next]) {
                dist[next] = dist[node] + 1;
                solve(next, node, vis, dist);
            }else if(next != root) mn = min(mn, abs(dist[node] - dist[next]) + 1); 
        }
    }
};


class Solution_02 {
    vector<vector<int>> graph;
    int mn = INT_MAX;
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        graph.resize(n, vector<int>());
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++){
           vector<bool> vis(n, false); unordered_map<int, int> dist; dist[i] = 0;
           solve(i, -1, vis, dist);
        }
        return mn == INT_MAX ? -1 : mn;
    }
    
    void solve(int node, int root, vector<bool> &vis, unordered_map<int, int> &dist){
        vis[node] = true;
        for(int next:graph[node]){
            if(!vis[next]) {
                dist[next] = dist[node] + 1;
                solve(next, node, vis, dist);
            }else if(next != root) mn = min(mn, abs(dist[node] - dist[next]) + 1); 
        }
    }
};