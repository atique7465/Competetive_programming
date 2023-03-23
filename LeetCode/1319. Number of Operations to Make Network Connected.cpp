class Solution {
    vector<int> root;
    vector<int> size;
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        root.resize(n);
        for(int i = 0; i < n; i++) root[i] = i;
        size.resize(n, 1);

        for(int i = 0; i < connections.size(); i++) union_by_size(connections[i][0], connections[i][1]);
        for(int i = 0; i < n; i++) findRoot(i);

        unordered_map<int, int> groups;
        for(int r:root) groups[r]++;

        int minRequiredForGroups = 0;
        for(auto const&[k,v]:groups) minRequiredForGroups+=v-1;
        int extraNeed = groups.size() - 1; 
        
        if(minRequiredForGroups + extraNeed <= connections.size()) return extraNeed;
        else return -1;
    }

    int findRoot(int child){
        if(root[child]==child) return child;
        return root[child] = findRoot(root[child]);
    }

    void union_by_size(int a, int b){
        int root_a = findRoot(a);
        int root_b = findRoot(b);
        if(root_a != root_b) {
            if(size[root_a] < size[root_b]){
                root[root_a] = root_b;
                size[root_b] += size[root_a];
            }else{
                root[root_b] = root_a;
                size[root_a] += size[root_b];
            }
        }
    }
};