#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_Inorder_2P {
public:
    bool findTarget(TreeNode *root, int k) {
        vector<int> v;
        inOrder(root, v);

        int len = v.size();
        int i = 0, j = len - 1;
        while (i < j) {
            if (v[i] + v[j] == k) {
                return true;
            } else if (v[i] + v[j] < k) {
                i++;
            } else {
                j--;
            }
        }

        return false;
    }

    void inOrder(TreeNode *root, vector<int> &v) {

        if (root == nullptr) {
            return;
        }

        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
};

class Solution_HashSet {

    unordered_set<int> st;
    int target = 0;

public:
    bool findTarget(TreeNode *root, int k) {
        target = k;
        return dfs(root);
    }

    bool dfs(TreeNode *root) {

        if (root == nullptr) {
            return false;
        }

        if (st.count(target - root->val)) return true;

        st.insert(root->val);

        return dfs(root->left) || dfs(root->right);
    }
};