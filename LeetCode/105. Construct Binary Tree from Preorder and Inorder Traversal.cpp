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
    int idx = 0;
    unordered_map<int, int>mp;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]]=i; 
        return solve(0, inorder.size()-1, preorder, inorder);
    }
    
    TreeNode* solve(int i, int j, vector<int>& preorder, vector<int>& inorder){
        
        TreeNode* root = new TreeNode(preorder[idx]);
        if(i == j) return root;
        
        int pos = mp[preorder[idx]];
        
        if(pos > i){
            idx++;
            root->left = solve(i, pos - 1, preorder, inorder);
        }
        
        if(pos < j){
            idx++;
            root->right = solve(pos + 1, j, preorder, inorder);
        }

        return root;
    }
};