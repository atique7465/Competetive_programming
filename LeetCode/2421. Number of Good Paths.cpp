class Solution {
    vector<int>parent;
    vector<int>size;
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        for(int i = 0; i < vals.size(); i++) parent.push_back(i);
        size.resize(vals.size(), 1);
        
        vector<vector<int>> tree(vals.size());
        for(int i = 0; i < edges.size(); i++){
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }

        map<int, vector<int>> nodeToValue;
        for(int i = 0; i < vals.size(); i++) nodeToValue[vals[i]].push_back(i);

        int goodPaths = 0;
        for(auto &[value,nodes]:nodeToValue){
            for(int node:nodes){
               for(int neighbor:tree[node]){
                   if(vals[node]>=vals[neighbor]) union_by_size(node, neighbor);
               }
            }

            unordered_map<int, int> group;
            for(int node:nodes) group[findParent(node)]++;
            for(auto&[k,v]:group) goodPaths += (v*(v+1)) / 2;
        }

        return goodPaths;
    }

    int findParent(int v){
        if(parent[v]==v) return v;
        return parent[v] = findParent(parent[v]);
    }

    void union_by_size(int a, int b){
         int parent_a = findParent(a);
         int parent_b = findParent(b);
         if(parent_a == parent_b) return;
         if(size[parent_a] < size[parent_b]){
             parent[parent_a] = parent[parent_b];
             size[parent_b] += size[parent_a];
         }else{
              parent[parent_b] = parent[parent_a];
              size[parent_a] += size[parent_b];
         }
    }
};