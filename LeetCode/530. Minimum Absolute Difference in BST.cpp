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
    vector<int>v;
public:
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        int mnDiff = INT_MAX;
        for(int i = 1; i < v.size(); i++) mnDiff = min(mnDiff, v[i] - v[i-1]); 
        return mnDiff;
    }

    void inOrder(TreeNode* root){
        if(root == NULL) return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
};