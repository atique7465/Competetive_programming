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
    unordered_map<TreeNode*, pair<int, int>> dp;
    int ans = 0;
public:
    int longestZigZag(TreeNode* root) {
        solve(root, 0);
        return ans - 1;
    }

    int solve(TreeNode* root, int dir){

        if(!root) return 0;
        if(dp.find(root) != dp.end()) return dir ? dp[root].first : dp[root].second;

        int left = 1 + solve(root->left, 0);
        int right = 1 + solve(root->right, 1);

        ans = max(ans, max(left, right));

        dp[root] = {left, right};
        
        return dir ? left : right;
    }
};