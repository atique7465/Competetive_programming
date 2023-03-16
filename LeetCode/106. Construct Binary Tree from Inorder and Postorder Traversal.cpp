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
    unordered_map<int, int>inMap;
    int postIdx;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        postIdx = postorder.size() - 1;
        return solve(0, inorder.size() - 1, postorder);
    }

    TreeNode* solve(int i, int j, vector<int>& postorder){
        TreeNode* root = new TreeNode(postorder[postIdx]);
        if(i == j) {postIdx--; return root;}
        int inIdx = inMap[postorder[postIdx]];
        postIdx--;
        if(inIdx < j) root->right = solve(inIdx + 1, j, postorder);
        if(inIdx > i) root->left = solve(i, inIdx - 1, postorder);
        return root;
    }
};