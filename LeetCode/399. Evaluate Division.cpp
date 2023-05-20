class Solution {
    map<string, map<string, double>> graph;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i = 0; i < equations.size(); i++){
            string from = equations[i][0];
            string to = equations[i][1];
            graph[from][to] = values[i];
            graph[to][from] = 1 / values[i];
        }

        vector<double> res;
        for(int i = 0; i < queries.size(); i++)
            res.push_back(solve(queries[i][0], queries[i][1]));

        return res;
    }

    double solve(string from, string to){

        if(from == to && graph.find(from) != graph.end()) return 1.0;

        map<string, bool> visited;
        visited[from] = true;

        queue<pair<string, double>> q;
        q.push({from, 1.0});
        
        while(!q.empty()){
            pair<string, double> root = q.front(); q.pop();

            for(auto const&[k,v]:graph[root.first]){
                if(visited.find(k) == visited.end()){
                   if(k == to) return root.second * v;
            
                   q.push({k, root.second * v});
                   visited[k] = true;
                }
            }
        } 

        return -1.0;
    }
};