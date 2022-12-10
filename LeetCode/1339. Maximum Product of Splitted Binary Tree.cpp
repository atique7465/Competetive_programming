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
    long long total = 0, part1, part2, prev1 = 0, prev2 = 0;
public:
    int maxProduct(TreeNode* root) {
        total = sumCount(root);
        solve(root);
        return (prev1 * prev2) % 1000000007;
    }

    long long sumCount(TreeNode* root){
        if(!root) return 0;
        return root->val = root->val + sumCount(root->left) + sumCount(root->right);
    }

    void solve(TreeNode* root){
        if(!root) return;
        part1 = root->val, part2 = total - root->val;
        if(part1 >= prev1 && part2 >= prev2){
            prev1 = part1; prev2 = part2;
        }else if((part1 > prev1 || part2 > prev2) && abs(part1-part2) < abs(prev1-prev2)){
            prev1 = part1; prev2 = part2;
        }
        solve(root->left); solve(root->right);
    }
};