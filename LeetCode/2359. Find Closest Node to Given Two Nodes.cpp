class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1); dist1[node1] = 0;
        vector<int> dist2(n, -1); dist2[node2] = 0;
        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);

        int res = INT_MAX, idx = -1;
        for(int i = 0; i < n; i++){
            if(dist1[i] != -1 && dist2[i] != -1){
                if(res > max(dist1[i], dist2[i])){
                    res = max(dist1[i], dist2[i]);
                    idx = i;
                }
            }
        }

        return idx;
    }

    void bfs(int node, vector<int>& edges, vector<int> &dist){
        queue<pair<int, int>>q;
        q.push({node, 0});
        while(!q.empty()){
            auto [curr, level] = q.front(); q.pop();
            int next = edges[curr];
            if(next != -1 && dist[next] == -1){
                dist[next] = level + 1;
                if(edges[next] != -1) q.push({next, level + 1});
            }
        }
    }
};