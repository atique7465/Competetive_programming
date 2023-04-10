class Solution {
    vector<vector<int>> graph, dp; vector<bool> visited, instack;
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {        
        int n = colors.size();
        visited.resize(n, false); instack.resize(n, false); 
        dp.resize(n, vector<int>(26, 0));
        graph.resize(n, vector<int>());

        for(int i = 0; i < edges.size(); i++) graph[edges[i][0]].push_back(edges[i][1]);

        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, solve(i, colors));

        return ans == INT_MAX? -1 : ans;
    }

   int solve(int node, string& colors){
        if(instack[node]) return INT_MAX;
        if(visited[node]) return dp[node][colors[node]-'a'];

        visited[node] = true; instack[node] = true;

        for(int next:graph[node]){
            if(solve(next, colors) == INT_MAX) return INT_MAX;
            for(int i = 0; i < 26; i++) dp[node][i] = max(dp[node][i], dp[next][i]);
        }

        instack[node] = false;
        return ++dp[node][colors[node]-'a'];
    }
};