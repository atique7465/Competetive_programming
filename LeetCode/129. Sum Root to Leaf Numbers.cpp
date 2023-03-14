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
    int sum = 0;
    vector<int> v;
public:
    int sumNumbers(TreeNode* root) {
        solve(root);
        return sum;
    }

    void solve(TreeNode* root){
        if(!root) return;
        v.push_back(root->val);
        solve(root->left);
        solve(root->right);
        if(root->left == NULL && root->right == NULL) sum += getIntVal();
        v.pop_back();
    }

    int getIntVal(){
        int value = 0, base = 1;
        for(int i = v.size()-1; i>=0; i--){
            value += v[i] * base;
            if(i>0) base*=10;
        }
        return value;
    }
};