class Solution {
    vector<int>parent;
    vector<int>size;
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < 26; i++) parent.push_back(i);
        size.resize(26, 1);
        
        for(int i = 0; i < s1.size(); i++) union_by_size(s1[i]-'a', s2[i]-'a');

        map<int, char> mp;
        for(int i = 0; i < 26; i++){
            int parent = findParent(i);
            char ch = 'a' + i;
            if(mp.find(parent) == mp.end()) mp[parent] = ch;
            else mp[parent] = min(mp[parent], ch);
        }

        for(int i = 0; i < baseStr.size(); i++) baseStr[i] = mp[findParent(baseStr[i]-'a')];

        return baseStr;
    }

    int findParent(int v){
        if(parent[v]==v) return v;
        return parent[v] = findParent(parent[v]);
    }

    void union_by_size(int a, int b){
        int parent_a = findParent(a);
        int parent_b = findParent(b);
        if(parent_a == parent_b) return;
        else if(size[parent_a] < size[parent_b]){
            parent[parent_a] = parent[parent_b];
            size[parent_b] += size[parent_a];
        }else{
            parent[parent_b] = parent[parent_a];
            size[parent_a] += size[parent_b];
        }
    }

};