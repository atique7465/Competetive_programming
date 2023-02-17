/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int>nodes;
public:
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        int res = INT_MAX;
        for(int i = 1; i < nodes.size(); i++) res = min(res, nodes[i] - nodes[i-1]);
        return res;
    }

    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        nodes.push_back(root->val);
        inOrder(root->right);
    }
};