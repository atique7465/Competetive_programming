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

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves_1;
        vector<int> leaves_2;
        findLeefs(root1, leaves_1);
        findLeefs(root2, leaves_2);
        return leaves_1 == leaves_2;
    }
    
    void findLeefs(TreeNode* root,  vector<int>& leaves){
        if(root == NULL) return;
        if(root->left==NULL && root->right==NULL) leaves.push_back(root->val);
        findLeefs(root->left, leaves);
        findLeefs(root->right, leaves);
    }
};