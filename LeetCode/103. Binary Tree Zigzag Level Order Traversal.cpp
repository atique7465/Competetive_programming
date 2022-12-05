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
    vector<vector<int>> res;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 1);
        for(int i = 1; i < res.size(); i+=2){
           int lo = 0, hi = res[i].size()-1;
            while(lo < hi){
                swap(res[i][lo], res[i][hi]);
                lo++; hi--;
            }
        }
        return res;
    }
    
    void dfs(TreeNode* root, int height){
        if(root == NULL) return;
        if(res.size() < height) res.push_back({root->val});
        else res[height-1].push_back(root->val);
        dfs(root->left, height+1);
        dfs(root->right, height+1);
    }
};