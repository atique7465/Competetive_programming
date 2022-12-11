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
    int mxPath = INT_MIN; 
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mxPath;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = max(dfs(root->left),0); 
        int right = max(dfs(root->right),0);
        mxPath = max(mxPath, root->val + left + right);

        return max(root->val, root->val + max(left, right));
    }
};