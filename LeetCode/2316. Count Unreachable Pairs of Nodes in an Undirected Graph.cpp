class Solution {
    vector<int>parent;
    vector<int>size;
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) parent.push_back(i);
        size.resize(n, 1);
        
        for(int i = 0; i < edges.size(); i++) union_by_size(edges[i][0], edges[i][1]);
        for(int i = 0; i < n; i++) findParent(i);

        unordered_map<int, int> groups;
        for(int i = 0; i < n; i++) groups[parent[i]]++;

        vector<long long> counts;
        for(auto const&[k,v]:groups) counts.push_back(v);
        for(int i = 1; i < counts.size(); i++) counts[i] += counts[i-1];

        long long res = 0;
        for(int i = 0; i < counts.size() - 1; i++) {
            long long a = i == 0 ? counts[i] : (counts[i] - counts[i-1]);
            long long b = counts[counts.size()-1] - counts[i];
            res += a * b;
        }

        return res;
    }

    int findParent(int child){
        if(child == parent[child]) return child;
        return parent[child] = findParent(parent[child]);
    }

    void union_by_size(int a, int b){
        int parent_a = findParent(a);
        int parent_b = findParent(b);
        if(parent_a != parent_b){
            if(size[parent_a] < size[parent_b]){
                parent[parent_a] = parent[parent_b];
                size[parent_b] += size[parent_a];
            }else{
                parent[parent_b] = parent[parent_a];
                size[parent_a] += size[parent_b];
            }
        }
    }
};