#include <bits/stdc++.h>

using namespace std;

class DSU {
    int parent[100];
    int sz[100], i;

public:
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        for (i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    ///path compression.
    int find_root(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_root(parent[v]);
    }

    /// balancing the tree.
    void union_by_size(int a, int b) {
        int root_a = find_root(a);
        int root_b = find_root(b);
        if (root_a != root_b) {
            if (sz[root_a] < sz[root_b]) {
                parent[root_a] = parent[root_b];
                sz[root_b] += sz[root_a];
            } else {
                parent[root_b] = parent[root_a];
                sz[root_a] += sz[root_b];
            }
        }
    }
};

class Solution {

public:
    bool equationsPossible(vector<string> &equations) {

        DSU *dsu = new DSU(26);

        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '=') {
                int xi = equations[i][0] - 'a';
                int yi = equations[i][3] - 'a';
                dsu->union_by_size(xi, yi);
            }
        }

        bool result = true;

        for (int i = 0; i < equations.size(); i++) {
            int xi = equations[i][0] - 'a';
            int yi = equations[i][3] - 'a';
            if (equations[i][1] == '=') {
                if (dsu->find_root(xi) != dsu->find_root(yi)) {
                    result = false;
                    break;
                }
            } else {
                if (dsu->find_root(xi) == dsu->find_root(yi)) {
                    result = false;
                    break;
                }
            }
        }

        return result;
    }
};