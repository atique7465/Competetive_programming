class Solution {
    unordered_map<int, vector<pair<int, int>>> graph;
    int minDist = INT_MAX;
    vector<bool> visited;
public:
    int minScore(int n, vector<vector<int>>& roads) {
        visited.resize(n+1, false);
        for(int i = 0; i < roads.size(); i++){
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        solve(1);
        return minDist;
    }

    void solve(int i){
        visited[i] = true;
        for(int j = 0; j < graph[i].size(); j++){
            int next = graph[i][j].first;
            int dist = graph[i][j].second;
            minDist = min(minDist, dist);
            if(!visited[next]) solve(next);
        }
    }
};