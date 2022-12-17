class Solution {
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
public:
    int longestConsecutive(vector<int>& nums) {

        initDsu(nums);
        
        for(int i = 0; i < nums.size(); i++){
           if(size.find(nums[i]+1) != size.end()) unionBySize(nums[i], nums[i]+1);
           if(size.find(nums[i]-1) != size.end()) unionBySize(nums[i], nums[i]-1);
        }

        int res = 0;
        for(auto const&[k,v]:size) res = max(res, v);

        return res;
    }

    void initDsu(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            parent[nums[i]] = nums[i];
            size[nums[i]] = 1;
        }
    }

    void unionBySize(int a, int b){
        int root_a = findRoot(a);
        int root_b = findRoot(b);
        if(root_a != root_b){
            if(size[root_a] < size[root_b]){
                parent[root_a] = parent[root_b];
                size[root_b] += size[root_a];
            }else{
                parent[root_b] = parent[root_a];
                size[root_a] += size[root_b];
            }
        }
    }

    int findRoot(int v){
        if(v == parent[v]) return v;
        return parent[v] = findRoot(parent[v]);
    }
};