class Solution {
    vector<int> parent, size;
public:
    int numSimilarGroups(vector<string>& strs) {
        for(int i = 0; i < strs.size(); i++){
            parent.push_back(i);
            size.push_back(1);
        }

        for(int i = 0; i < strs.size(); i++){
            for(int j = 0; j < strs.size(); j++){
                if(j != i && match(strs[i], strs[j])) union_by_size(i, j);
            }
        }

        for(int i = 0; i < strs.size(); i++) find_root(i);

        unordered_set<int> groups;
        for(int i = 0; i < strs.size(); i++) groups.insert(parent[i]);

        return groups.size();
    }

    bool match(string a, string b){
        int mismatchCnt = 0;
        for(int i = 0; i < a.size(); i++) if(a[i] != b[i]) mismatchCnt++;
        return mismatchCnt == 2 || mismatchCnt == 0;
    }

    int find_root(int child){
        if(child == parent[child]) return child;
        return parent[child] = find_root(parent[child]);
    }

    void union_by_size(int a, int b) {
        int root_a = find_root(a);
        int root_b = find_root(b);
        if (root_a != root_b) {
            if (size[root_a] < size[root_b]) {
                parent[root_a] = parent[root_b];
                size[root_b] += size[root_a];
            } else {
                parent[root_b] = parent[root_a];
                size[root_a] += size[root_b];
            }
        }
    }
};